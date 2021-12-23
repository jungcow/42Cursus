#ifndef _Span_H__
#define _Span_H__

#include <exception>
#include <iostream>
#include <set>

class Span {
private:
  std::multiset<unsigned int> _arr;
  unsigned int                _totalSize;

public:
  Span();
  Span(unsigned int N);
  Span(const Span &other);
  ~Span();
  Span &operator=(const Span &other);

  void addNumber(unsigned int num);

  template <typename _InputIterator>
  void addNumber(_InputIterator _f, _InputIterator _l);

  const std::multiset<unsigned int> &getArray(void) const;

  unsigned int shortestSpan(void);
  unsigned int longestSpan(void);
};

template <typename _InputIterator>
void Span::addNumber(_InputIterator f, _InputIterator l) {
  for (; f != l; f++) {
    if (_arr.size() >= _totalSize)
      throw std::out_of_range("[ Error ] You Can't Add, It's Full\n");
    _arr.insert(*f);
  }
}

#endif