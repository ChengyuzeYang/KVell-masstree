#include <algorithm>
#include <stdexcept>
#include <thread>
#include <unistd.h>

#include "masstree/wrapper.hh"
#include "one_masstree.h"
#include "memory-item.h"

using MT_manager = masstree_manager_test;

// Functions with "_test" suffix are to test.

extern "C"
{
  mt_manager_t *one_masstree_create(int worker_id) {
    // MT_manager_MANAGER *mt = new MT_manager();
    MT_manager *mt = new MT_manager(threadinfo::make(threadinfo::TI_PROCESS,worker_id));
    return mt;
  }

  int one_masstree_find(mt_manager_t *t, unsigned char* k, size_t len, ValueType *e) {
    MT_manager *mt = static_cast< MT_manager* >(t);
    uint64_t hash = *(uint64_t*)k;
    return mt->client_.get(hash,e);
  }

  void one_masstree_delete(mt_manager_t *t, unsigned char*k, size_t len) {
    MT_manager *mt = static_cast< MT_manager* >(t);
    uint64_t hash = *(uint64_t*)k;
    mt->client_.remove(hash);
  }

  void one_masstree_insert(mt_manager_t *t, unsigned char*k, size_t len, ValueType *e) {
    MT_manager *mt = static_cast< MT_manager* >(t);
    uint64_t hash = *(uint64_t*)k;
    mt->client_.put(hash,*e);
  }

  struct index_scan one_masstree_find_n(mt_manager_t *t, unsigned char* k, size_t len, size_t n) {
    struct index_scan res;
    res.hashes = (uint64_t*) malloc(n*sizeof(*res.hashes));
    res.entries = (struct index_entry*) malloc(n*sizeof(*res.entries));
    res.nb_entries = 0;

    MT_manager *mt = static_cast< MT_manager* >(t);
    uint64_t l_key = *(uint64_t*)k;
    uint64_t r_key = UINT_MAX;
    mt->client_.scan(l_key, r_key, n, &res);
    return res;
  }

  // struct index_scan masstree_find_n_test(MT_manager *t, KeyType k, size_t n) {
  //   struct index_scan res;
  //   res.hashes = (KeyType*) malloc(n*sizeof(*res.hashes));
  //   res.entries = (ValueType*) malloc(n*sizeof(*res.entries));
  //   res.nb_entries = 0;

  //   KeyType l_key = k;
  //   KeyType r_key = UINT_MAX;
  //   scan_values(t, l_key, r_key, n, &res);
  //   return res;
  // }

  void one_masstree_free(mt_manager_t *t) {
    MT_manager *mt = static_cast< MT_manager* >(t);
    delete mt;
  }

  void one_masstree_init_main(void){
    threadinfo *main_ti = threadinfo::make(threadinfo::TI_MAIN, -1);
    main_ti->pthread() = pthread_self();
    MT_manager::setup(main_ti,initialize);
    MT_manager main_mtt(main_ti);
    return;
  }
}