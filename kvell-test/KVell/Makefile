CC=clang  #If you use GCC, add -fno-strict-aliasing to the CFLAGS because the Google BTree does weird stuff
#CFLAGS=-Wall -O0 -ggdb3
CFLAGS=-O2 -ggdb3 -Wall -fPIC

CXX=g++
MASSTREE_ROOT=../../masstree-wrapper-master
MASSTREE_LINKS=-I ${MASSTREE_ROOT}/include -include masstree_wrapper.hpp -I ${MASSTREE_ROOT}/src -include mt_wrapper.h -I ${MASSTREE_ROOT}/build/_deps/src
CXXFLAGS= ${CFLAGS} -std=c++11 ${MASSTREE_LINKS}

LDLIBS=-L ${MASSTREE_ROOT}/build -lmttest -lm -lpthread -lstdc++

INDEXES_OBJ=indexes/rbtree.o indexes/rax.o indexes/art.o indexes/btree.o indexes/masstree.o
MAIN_OBJ=main.o slab.o freelist.o ioengine.o pagecache.o stats.o random.o slabworker.o workload-common.o workload-ycsb.o workload-production.o utils.o in-memory-index-rbtree.o in-memory-index-rax.o in-memory-index-art.o in-memory-index-btree.o in-memory-index-masstree.o ${INDEXES_OBJ}
MICROBENCH_OBJ=microbench.o random.o stats.o utils.o ${INDEXES_OBJ}
BENCH_OBJ=benchcomponents.o pagecache.o random.o $(INDEXES_OBJ)


.PHONY: all clean

all: makefile.dep main microbench benchcomponents

makefile.dep: *.[Cch] indexes/*.[ch] indexes/*.cc indexes/*.cpp
	for i in *.[Cc]; do ${CC} -MM "$${i}" ${CFLAGS}; done > $@
	for i in indexes/*.c; do ${CC} -MM "$${i}" -MT $${i%.c}.o ${CFLAGS}; done >> $@
	for i in indexes/*.cc; do ${CXX} -MM "$${i}" -MT $${i%.cc}.o ${CXXFLAGS}; done >> $@
	for i in indexes/*.cpp; do $(CXX) -MM "$${i}" -MT $${i%.cc}.o ${CXXFLAGS}; done >> $@
	#find ./ -type f \( -iname \*.c -o -iname \*.cc \) | parallel clang -MM "{}" -MT "{.}".o > makefile.dep #If you find that the lines above take too long...

-include makefile.dep

main: $(MAIN_OBJ)
	$(CXX) $(MAIN_OBJ) -o main ${LDLIBS}

microbench: $(MICROBENCH_OBJ)
	$(CXX) $(MICROBENCH_OBJ) -o microbench ${LDLIBS}

benchcomponents: $(BENCH_OBJ)
	$(CXX) $(BENCH_OBJ) -o benchcomponents ${LDLIBS}

clean:
	rm -f *.o indexes/*.o main microbench benchcomponents

