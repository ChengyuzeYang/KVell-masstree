#include "headers.h"
//#include "masstree_wrapper.hpp"
#include "indexes/one_masstree.h"

static uint64_t get_prefix_for_item(char *item) {
   struct item_metadata *meta = (struct item_metadata *)item;
   char *item_key = &item[sizeof(*meta)];
   return *(uint64_t*)item_key;
}

/* In memory MassTree */

//static masstree_t **items_locations;
mt_manager_t **items_locations;
static __thread index_entry_t tmp_entry;
static pthread_spinlock_t *items_location_locks;

index_entry_t *one_masstree_worker_lookup(int worker_id, void *item) {
   uint64_t hash = get_prefix_for_item(item);
   int res = one_masstree_find(items_locations[worker_id], (unsigned char*)&hash, sizeof(hash), &tmp_entry);
   if(res)
      return &tmp_entry;
   else
      return NULL;
}
void one_masstree_worker_insert(int worker_id, void *item, index_entry_t *e) {
   uint64_t hash = get_prefix_for_item(item);

   pthread_spin_lock(&items_location_locks[worker_id]);
   //print_item(worker_id,item);
   one_masstree_insert(items_locations[worker_id], (unsigned char*)&hash, sizeof(hash), e);
   pthread_spin_unlock(&items_location_locks[worker_id]);
}
void one_masstree_worker_delete(int worker_id, void *item) {
   index_entry_t *old_entry = NULL;
   uint64_t hash = get_prefix_for_item(item);

   pthread_spin_lock(&items_location_locks[worker_id]);
   one_masstree_delete(items_locations[worker_id], (unsigned char *)&(hash), sizeof(hash));
   pthread_spin_unlock(&items_location_locks[worker_id]);

   if(old_entry)
      free(old_entry);
}

void one_masstree_index_add(struct slab_callback *cb, void *item) {
   index_entry_t *new_entry = (index_entry_t*) malloc(sizeof(index_entry_t));
   new_entry->slab = cb->slab;
   new_entry->slab_idx = cb->slab_idx;
   one_masstree_worker_insert(get_worker(new_entry->slab), item, new_entry);
   // one_masstree_worker_insert(get_worker(cb->slab), item, new_entry);
}


/*
 * Returns up to scan_size keys >= item.key.
 * If item is not in the database, this will still return up to scan_size keys > item.key.
 */
struct index_scan one_masstree_init_scan(void *item, size_t scan_size) {
   struct index_scan scan_res;
   size_t nb_workers = get_nb_workers();
   uint64_t hash = get_prefix_for_item(item);

   struct index_scan *res = malloc(nb_workers * sizeof(*res));
   for(size_t w = 0; w < nb_workers; w++) {
      pthread_spin_lock(&items_location_locks[w]);
      res[w] = one_masstree_find_n(items_locations[w], (unsigned char *)&(hash), sizeof(hash), scan_size);
      pthread_spin_unlock(&items_location_locks[w]);
   }

   scan_res.entries = malloc(scan_size * sizeof(*scan_res.entries));
   scan_res.hashes = malloc(scan_size * sizeof(*scan_res.hashes));
   scan_res.nb_entries = 0;

   size_t *positions = calloc(nb_workers, sizeof(*positions));
   while(scan_res.nb_entries < scan_size) {
      size_t min_worker = nb_workers;
      uint64_t min_hash = 0;
      index_entry_t *min_entry = NULL;
      for(size_t w = 0; w < nb_workers; w++) {
         if(res[w].nb_entries <= positions[w]) {
            continue; // no more item to read in that masstree
         } else {
            uint64_t current_hash = res[w].hashes[positions[w]];
            if(!min_entry || current_hash < min_hash) {
               min_hash = current_hash;
               min_entry = &res[w].entries[positions[w]];
               min_worker = w;
            }
         }
      }
      if(min_worker == nb_workers)
         break; // no worker has any scannable item left
      positions[min_worker]++;
      scan_res.hashes[scan_res.nb_entries] = min_hash;
      scan_res.entries[scan_res.nb_entries] = *min_entry;
      scan_res.nb_entries++;
   }
   for(size_t w = 0; w < nb_workers; w++) {
      free(res[w].hashes);
      free(res[w].entries);
   }
   free(res);
   free(positions);

   return scan_res;
}

/*struct index_scan one_masstree_init_scan(void *item, size_t scan_size) {
   struct index_scan scan_res;
   size_t nb_workers = get_nb_workers();
   uint64_t hash = get_prefix_for_item(item);

   struct index_scan *res = malloc(nb_workers * sizeof(*res));
   for(size_t w = 0; w < nb_workers; w++) {
      pthread_spin_lock(&items_location_locks[w]);
      res[w] = one_masstree_find_n(items_locations[w], (unsigned char *)&(hash), sizeof(hash), scan_size);
      pthread_spin_unlock(&items_location_locks[w]);
   }

   one_masstree_t *b = one_masstree_create();
   for(size_t w = 0; w < nb_workers; w++) {
      for(size_t i = 0; i < res[w].nb_entries; i++) {
         one_masstree_insert(b, (unsigned char*)&(res[w].hashes[i]), sizeof(res[w].hashes[i]), &res[w].entries[i]);
      }
   }
   scan_res = one_masstree_find_n(b, (unsigned char *)&(hash), sizeof(hash), scan_size);
   for(size_t w = 0; w < nb_workers; w++) {
      free(res[w].hashes);
      free(res[w].entries);
   }
   free(res);
   one_masstree_free(b);

   return scan_res;
}*/

void one_masstree_init(void) {
   items_locations = malloc(get_nb_workers() * sizeof(*items_locations));
   items_location_locks = malloc(get_nb_workers() * sizeof(*items_location_locks));
   one_masstree_init_main();
   for(size_t w = 0; w < get_nb_workers() ; w++) {
      items_locations[w] = one_masstree_create(w);
      pthread_spin_init(&items_location_locks[w], PTHREAD_PROCESS_PRIVATE);
   }
}


