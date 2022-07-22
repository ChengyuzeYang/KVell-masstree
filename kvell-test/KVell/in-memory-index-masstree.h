#ifndef IN_MEMORY_MASSTREE
#define IN_MEMORY_MASSTREE 1

#include "indexes/masstree.h"

#define INDEX_TYPE "masstree"
#define memory_index_init masstree_init
#define memory_index_add masstree_index_add
#define memory_index_lookup masstree_worker_lookup
#define memory_index_delete masstree_worker_delete
#define memory_index_scan masstree_init_scan

void masstree_init(void);
struct index_entry *masstree_worker_lookup(int worker_id, void *item);
void masstree_worker_delete(int worker_id, void *item);
struct index_scan masstree_init_scan(void *item, size_t scan_size);
void masstree_index_add(struct slab_callback *cb, void *item);

#endif

