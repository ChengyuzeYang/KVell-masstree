#ifndef IN_MEMORY_MASSTREE
#define IN_MEMORY_MASSTREE 1

#include "indexes/one_masstree.h"

#define INDEX_TYPE "one-masstree"
#define memory_index_init one_masstree_init
#define memory_index_add one_masstree_index_add
#define memory_index_lookup one_masstree_worker_lookup
#define memory_index_delete one_masstree_worker_delete
#define memory_index_scan one_masstree_init_scan

void one_masstree_init(void);
struct index_entry *one_masstree_worker_lookup(int worker_id, void *item);
void one_masstree_worker_delete(int worker_id, void *item);
struct index_scan one_masstree_init_scan(void *item, size_t scan_size);
void one_masstree_index_add(struct slab_callback *cb, void *item);

#endif

