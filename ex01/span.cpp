#include "span.hpp"

Span::Span() { _totalSize = 0; }
Span::~Span() {}
Span::Span(unsigned int N) { _totalSize = N; }
Span::Span(const Span &other) { *this = other; }

Span &Span::operator=(const Span &other) {
  _arr = other.getArray();
  _totalSize = other._totalSize;
  return *this;
}

void Span::addNumber(unsigned int num) {
  if (_arr.size() >= _totalSize)
    throw std::out_of_range("[ Error ] You Can't Add, It's Full\n");
  _arr.insert(num);
}

const std::multiset<unsigned int> &Span::getArray() const { return (_arr); }

unsigned int Span::shortestSpan(void) {
  if (_arr.size() <= 1)
    throw std::logic_error("[ Error ] Num is Not Enough");
  std::multiset<unsigned int>::iterator si;
  std::multiset<unsigned int>           diffmultiset;
  for (si = _arr.begin(); si != _arr.end(); si++)
    diffmultiset.insert(*(++si) - *(--si));
  return *(diffmultiset.begin());
}

unsigned int Span::longestSpan() {
  if (_arr.size() <= 1)
    throw std::logic_error("[ Error ] Num is Not Enough");
  std::multiset<unsigned int>::iterator si = _arr.end();
  return (*(--si) - *(_arr.begin()));
}