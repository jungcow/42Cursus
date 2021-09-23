#ifndef _ITER_H__
#define _ITER_H__

#include <iostream>

template <typename T> void iter(T *Array, long size, void (*fptr)(T element)) {
  if (!Array || size <= 0)
    return;
  for (long i = 0; i < size; i++) {
    (*fptr)(Array[i]);
  }
}

template <typename T> void printArray(T element) {
  std::cout << element << std::endl;
}

#endif