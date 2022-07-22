#include <algorithm>
#include <stdexcept>
#include <thread>
#include <unistd.h>

#define GLOBAL_VALUE_DEFINE
#include "masstree_wrapper.hpp"
#include "mt_wrapper.h"
#include "memory-item.h"

using KeyType = uint64_t;
using ValueType = index_entry_t;
//using ValueType = uint64_t;
using MT = MasstreeWrapper<ValueType>;

alignas(64) KeyType max_key = 30;
KeyType insert_key = 0;
KeyType update_key = 0;
KeyType remove_key = 0;

bool get_value(MT *mt, KeyType key, ValueType *value_p) {
  KeyType key_buf{__builtin_bswap64(key)};
  return mt->get_value(reinterpret_cast<char *>(&key_buf), sizeof(key_buf), value_p);
}

bool insert_value(MT *mt, KeyType key, ValueType value) {
  KeyType key_buf{__builtin_bswap64(key)};
  return mt->insert_value(reinterpret_cast<char *>(&key_buf), sizeof(key_buf),
                          value);
}

bool update_value(MT *mt, KeyType key, ValueType value) {
  KeyType key_buf{__builtin_bswap64(key)};
  return mt->update_value(reinterpret_cast<char *>(&key_buf), sizeof(key_buf),
                          value);
}

bool remove_value(MT *mt, KeyType key) {
  KeyType key_buf{__builtin_bswap64(key)};
  return mt->remove_value(reinterpret_cast<char *>(&key_buf), sizeof(key_buf));
}

void scan_values(MT *mt, KeyType l_key, KeyType r_key, int64_t count, struct index_scan *res) {
  KeyType l_key_buf{__builtin_bswap64(l_key)};
  KeyType r_key_buf{__builtin_bswap64(r_key)};

  bool l_exclusive = false;
  bool r_exclusive = false;

  uint64_t n_cnt = 0;
  uint64_t v_cnt = 0;

  mt->scan(
      reinterpret_cast<char *>(&l_key_buf), sizeof(l_key_buf), l_exclusive,
      reinterpret_cast<char *>(&r_key_buf), sizeof(r_key_buf), r_exclusive,
      {[&n_cnt](const MT::leaf_type *leaf, uint64_t version,
                bool &continue_flag) {
         n_cnt++;
         (void)leaf;
         (void)version;
         (void)continue_flag;
         return;
       },
       [&v_cnt,res](const MT::Str &key, const ValueType &val, bool &continue_flag) {
         KeyType actual_key{
             __builtin_bswap64(*(reinterpret_cast<const uint64_t *>(key.s)))};
         //printf("scanned key: %lu\n", actual_key);
         res->hashes[res->nb_entries] = actual_key;
         res->entries[res->nb_entries] = val;
         //printf("%lu\n", *val);
         res->nb_entries++;
         (void)val;
         (void)continue_flag;
         v_cnt++;
         return;
       }},
      count);

  //printf("n_cnt: %ld\n", n_cnt);
  //printf("v_cnt: %ld\n", v_cnt);
}

void rscan_values(MT *mt, KeyType l_key, KeyType r_key, int64_t count = -1) {
  KeyType l_key_buf{__builtin_bswap64(l_key)};
  KeyType r_key_buf{__builtin_bswap64(r_key)};

  bool l_exclusive = false;
  bool r_exclusive = false;

  uint64_t n_cnt = 0;
  uint64_t v_cnt = 0;

  mt->rscan(
      reinterpret_cast<char *>(&l_key_buf), sizeof(l_key_buf), l_exclusive,
      reinterpret_cast<char *>(&r_key_buf), sizeof(r_key_buf), r_exclusive,
      {[&n_cnt](const MT::leaf_type *leaf, uint64_t version,
                bool &continue_flag) {
         n_cnt++;
         (void)leaf;
         (void)version;
         (void)continue_flag;
         return;
       },
       [&v_cnt](const MT::Str &key, const ValueType &val, bool &continue_flag) {
         v_cnt++;
         KeyType actual_key{
             __builtin_bswap64(*(reinterpret_cast<const uint64_t *>(key.s)))};
         printf("rscanned key: %lu\n", actual_key);
         (void)val;
         (void)continue_flag;
         return;
       }},
      count);

  //printf("n_cnt: %ld\n", n_cnt);
  //printf("v_cnt: %ld\n", v_cnt);
}

void test_thread(MT *mt, std::size_t thid) {
  mt->thread_init(thid);
  // run_insert(mt);
  // remove_value(mt,12);
  // remove_value(mt,13);
  // ValueType tst = *get_value(mt,20);
  // printf("11's value = %lu\n",tst);
  // sleep(1);
  // run_scan(mt);
  // // run_update(mt);
  // sleep(1);
  // insert_value(mt,12,nullptr);
  // insert_value(mt,13,nullptr);
  // run_remove(mt);
}

int main() {
  //std::size_t n_cores = std::thread::hardware_concurrency();
  //std::size_t n_threads = std::max(std::size_t{1}, n_cores);
  std::size_t n_threads = 1;
  printf("n_threads: %ld\n", n_threads);

  MT mt;

  std::vector<std::thread> threads;
  threads.reserve(n_threads);

  for (size_t i = 0; i < n_threads; i++) {
    threads.emplace_back(test_thread, &mt, i);
  }

  for (std::size_t i = 0; i < n_threads; i++) {
    threads[i].join();
  }
}