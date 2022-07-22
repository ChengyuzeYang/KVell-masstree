#include <algorithm>
#include <stdexcept>
#include <thread>
#include <unistd.h>

#include "masstree_wrapper.hpp"
#include "mt_wrapper.h"
#include "masstree.h"
#include "memory-item.h"

// using KeyType = uint64_t;
using ValueType = struct index_entry;
using MT = MasstreeWrapper<ValueType>;

// Functions with "_test" suffix are to test.

extern "C"
{
  masstree_t *masstree_create(int worker_id) {
    // MT *mt = new MT();
    MT *mt = new MT();
    mt->thread_init(worker_id);
    return mt;
  }

  int masstree_find(masstree_t *t, unsigned char* k, size_t len, ValueType *e) {
    MT *mt = static_cast< MT* >(t);
    uint64_t hash = *(uint64_t*)k;
    return get_value(mt,hash,e);
    // auto i = get_value(mt,hash);
    // if(i) {
    //   *e = *i;
    //   return 1;
    // } else {
    //   return 0;
    // }
  }

  // int masstree_find_test(MT *t, KeyType k, ValueType *e) {
  //   //MT *mt = static_cast< MT* >(t);
  //   auto i = get_value(t,k);
  //   if(i) {
  //     *e = *i;
  //     return 1;
  //   } else {
  //     return 0;
  //   }
  // }

  void masstree_delete(masstree_t *t, unsigned char*k, size_t len) {
    MT *mt = static_cast< MT* >(t);
    uint64_t hash = *(uint64_t*)k;
    remove_value(mt,hash);
  }

  // void masstree_delete_test(MT *t, KeyType k) {
  //   remove_value(t,k);
  // }

  void masstree_insert(masstree_t *t, unsigned char*k, size_t len, ValueType *e) {
    MT *mt = static_cast< MT* >(t);
    uint64_t hash = *(uint64_t*)k;
    // struct index_entry *new_e = (struct index_entry *) malloc(sizeof(struct index_entry));
    // *new_e = *e;
    insert_value(mt,hash,*e);
  }

  // void masstree_insert_test(MT *t, KeyType k, ValueType *e) {
  //   insert_value(t,k,e);
  // }

  struct index_scan masstree_find_n(masstree_t *t, unsigned char* k, size_t len, size_t n) {
    struct index_scan res;
    res.hashes = (uint64_t*) malloc(n*sizeof(*res.hashes));
    res.entries = (ValueType*) malloc(n*sizeof(*res.entries));
    res.nb_entries = 0;

    MT *mt = static_cast< MT* >(t);
    uint64_t l_key = *(uint64_t*)k;
    uint64_t r_key = UINT_MAX;
    scan_values(mt, l_key, r_key, n, &res);
    return res;
  }

  // struct index_scan masstree_find_n_test(MT *t, KeyType k, size_t n) {
  //   struct index_scan res;
  //   res.hashes = (KeyType*) malloc(n*sizeof(*res.hashes));
  //   res.entries = (ValueType*) malloc(n*sizeof(*res.entries));
  //   res.nb_entries = 0;

  //   KeyType l_key = k;
  //   KeyType r_key = UINT_MAX;
  //   scan_values(t, l_key, r_key, n, &res);
  //   return res;
  // }

  void masstree_free(masstree_t *t) {
    MT *mt = static_cast< MT* >(t);
    delete mt;
  }
}