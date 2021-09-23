#ifndef _WHATEVER_H__
#define _WHATEVER_H__

template <typename T> void swap(T &a, T &b) {
  T t;
  t = a;
  a = b;
  b = t;
}

template <typename T> T min(T a, T b) {
  if (a < b)
    return a;
  return b;
}
template <typename T> T max(T a, T b) {
  if (a > b)
    return a;
  return b;
}

#endif