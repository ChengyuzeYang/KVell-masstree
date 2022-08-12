#ifndef ONE_one_masstree_H
#define ONE_one_masstree_H

#ifdef __cplusplus
extern "C" {
#endif

#include "memory-item.h"

typedef void mt_manager_t;

mt_manager_t *one_masstree_create(int worker_id);
int one_masstree_find(mt_manager_t *t, unsigned char*k, size_t len, struct index_entry *e);
void one_masstree_delete(mt_manager_t *t, unsigned char*k, size_t len);
void one_masstree_insert(mt_manager_t *t, unsigned char*k, size_t len, struct index_entry *e);
struct index_scan one_masstree_find_n(mt_manager_t *t, unsigned char* k, size_t len, size_t n);
void one_masstree_free(mt_manager_t *t);
void one_masstree_init_main(void);

#ifdef __cplusplus
}
#endif

#endif
