#ifndef MASSTREE_H
#define MASSTREE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "memory-item.h"

typedef void masstree_t;

masstree_t *masstree_create(int worker_id);
int masstree_find(masstree_t *t, unsigned char*k, size_t len, struct index_entry *e);
void masstree_delete(masstree_t *t, unsigned char*k, size_t len);
void masstree_insert(masstree_t *t, unsigned char*k, size_t len, struct index_entry *e);
struct index_scan masstree_find_n(masstree_t *t, unsigned char* k, size_t len, size_t n);
void masstree_free(masstree_t *t);

#ifdef __cplusplus
}
#endif

#endif
