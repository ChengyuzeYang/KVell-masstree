# KVell-masstree
[KVell](https://github.com/BLepers/KVell) provides 4 kinds of in-memory structures to build, we add a new structure masstree from [masstree-wrapper](https://github.com/wattlebirdaz/masstree-wrapper).

## Build && Execute

To run KVell-masstree on CentOS:

```
cd ~
git clone https://github.com/ChengyuzeYang/KVell-masstree.git
cd kvell-test/KVell

# Requirements

## gcc --version gcc (GCC) 9.3.1 20200408 (Red Hat 9.3.1-2)
scl enable devtoolset-9 bash 

## link the shared library libmttest.so
export LD_LIBRARY_PATH=YOUR-OWN-PATH/masstree-wrapper-master/build:$LD_LIBRARY_PATH

make

# For test
./main 1 1
```

We adjusted and made masstree-wrapper to a shared library in [libmttest.so](./masstree-wrapper-master/build/libmttest.so). Related work is under the masstree-wrapper-master folder.

For some other details you can refer to repositories mentioned above.
