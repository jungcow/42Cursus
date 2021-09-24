#ifndef _ITER_H__
#define _ITER_H__

#include <iostream>

class Awesome {
public:
  Awesome(void) : _n(42) { return; }
  int get(void) const { return this->_n; }

private:
  int _n;
};
std::ostream &operator<<(std::ostream &o, Awesome const &rhs) {
  o << rhs.get();
  return o;
}
template <typename T> void print(T const &x) {
  std::cout << x << std::endl;
  return;
}

template <typename T> void iter(T *Array, long size, void (*fptr)(T const &)) {
  if (!Array || size <= 0)
    return;
  for (long i = 0; i < size; i++) {
    (*fptr)(Array[i]);
  }
}

template <typename T> void printElement(T element) {
  std::cout << element << std::endl;
}

#endif