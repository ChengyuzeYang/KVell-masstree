#ifndef MEM_ITEM_H
#define MEM_ITEM_H

struct slab;
struct index_entry { // This index entry could be made much smaller by, e.g., have 64b for [slab_size, slab_idx] it is then easy to do size -> slab* given a slab context
   union {
      struct slab *slab;
      void *page;
   };
   union {
      size_t slab_idx;
      void *lru;
   };
};

typedef struct index_entry index_entry_t;

struct index_scan {
   uint64_t *hashes;
   index_entry_t *entries;
   size_t nb_entries;
};



#endif
