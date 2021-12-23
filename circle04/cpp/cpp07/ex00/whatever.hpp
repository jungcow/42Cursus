#ifndef _WHATEVER_H__
#define _WHATEVER_H__

#include <iostream>

class Awesome {
public:
  Awesome(void) : _n(0) {}
  Awesome(int n) : _n(n) {}
  Awesome &operator=(Awesome &a) {
    _n = a._n;
    return *this;
  }
  bool operator==(Awesome const &rhs) const { return (this->_n == rhs._n); }
  bool operator!=(Awesome const &rhs) const { return (this->_n != rhs._n); }
  bool operator>(Awesome const &rhs) const { return (this->_n > rhs._n); }
  bool operator<(Awesome const &rhs) const { return (this->_n < rhs._n); }
  bool operator>=(Awesome const &rhs) const { return (this->_n >= rhs._n); }
  bool operator<=(Awesome const &rhs) const { return (this->_n <= rhs._n); }
  int  get_n() const { return _n; }

private:
  int _n;
};
std::ostream &operator<<(std::ostream &o, const Awesome &a) {
  o << a.get_n();
  return o;
}

template <typename T> void swap(T &a, T &b) {
  T t;
  t = a;
  a = b;
  b = t;
}

template <typename T> T min(T const a, T const b) {
  if (a < b)
    return a;
  return b;
}
template <typename T> T max(T const a, T const b) {
  if (a > b)
    return a;
  return b;
}

#endif
