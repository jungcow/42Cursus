#ifndef _ARRAY_H__
#define _ARRAY_H__

#include <iostream>
#include <stdexcept>

template <typename T> class Array {
private:
  T *  _array;
  long _size;

public:
  Array();
  Array(unsigned int u);
  Array(const Array &other);
  ~Array();

  Array &  operator=(const Array &other);
  T &      operator[](int idx);
  T const &operator[](int idx) const;

  long size() const;
};

template <typename T> Array<T>::Array() {
  _array = new T[0];
  _size = 0;
}

template <typename T> Array<T>::~Array() { delete[] _array; }

template <typename T> Array<T>::Array(unsigned int u) {
  _array = new T[u];
  _size = u;
}

template <typename T> Array<T>::Array(const Array &other) {
  _array = new T[0];
  *this = other;
}

template <typename T> Array<T> &Array<T>::operator=(const Array &other) {
  delete[] _array;
  _array = new T[other.size()];
  _size = other.size();
  for (unsigned int i = 0; i < _size; i++) {
    _array[i] = other._array[i];
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](int idx) {
  if (idx < 0 || _size < idx + 1)
    throw std::out_of_range("Out Of Range");
  return _array[idx];
}

template <typename T> T const &Array<T>::operator[](int idx) const {
  if (idx < 0 || _size < idx + 1)
    throw std::out_of_range("Out Of Range");
  return _array[idx];
}

template <typename T> long Array<T>::size() const { return _size; }

#endif