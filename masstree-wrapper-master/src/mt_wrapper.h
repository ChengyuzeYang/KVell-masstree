#include <algorithm>
#include <stdexcept>
#include <thread>
#include <unistd.h>

#include "masstree_wrapper.hpp"

using KeyType = uint64_t;
using ValueType = struct index_entry;
//using ValueType = uint64_t;
using MT = MasstreeWrapper<ValueType>;

bool get_value(MT *mt, KeyType key, ValueType *value_p);
bool insert_value(MT *mt, KeyType key, ValueType value);
bool update_value(MT *mt, KeyType key, ValueType value);
bool remove_value(MT *mt, KeyType key);
void scan_values(MT *mt, KeyType l_key, KeyType r_key, int64_t count, struct index_scan *res);
void rscan_values(MT *mt, KeyType l_key, KeyType r_key, int64_t count);
void run_insert(MT *mt);
void run_update(MT *mt);
void run_remove(MT *mt);
void run_scan(MT *mt);
void run_rscan(MT *mt);
void test_thread(MT *mt, std::size_t thid);