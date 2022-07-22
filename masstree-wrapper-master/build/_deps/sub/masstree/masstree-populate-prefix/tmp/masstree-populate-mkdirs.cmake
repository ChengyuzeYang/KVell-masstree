# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ycyz/masstree-wrapper-master/build/_deps/src/masstree"
  "/home/ycyz/masstree-wrapper-master/build/_deps/build/masstree"
  "/home/ycyz/masstree-wrapper-master/build/_deps/sub/masstree/masstree-populate-prefix"
  "/home/ycyz/masstree-wrapper-master/build/_deps/sub/masstree/masstree-populate-prefix/tmp"
  "/home/ycyz/masstree-wrapper-master/build/_deps/sub/masstree/masstree-populate-prefix/src/masstree-populate-stamp"
  "/home/ycyz/masstree-wrapper-master/build/_deps/sub/masstree/masstree-populate-prefix/src"
  "/home/ycyz/masstree-wrapper-master/build/_deps/sub/masstree/masstree-populate-prefix/src/masstree-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ycyz/masstree-wrapper-master/build/_deps/sub/masstree/masstree-populate-prefix/src/masstree-populate-stamp/${subDir}")
endforeach()
