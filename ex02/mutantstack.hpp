#ifndef _MUTANTSTACK_H__
#define _MUTANTSTACK_H__

#include <iostream>
#include <stack>

template <typename T> class MutantStack : public std::stack<T> {
public:
  MutantStack() : std::stack<T>() {}

  typedef typename std::stack<T>                  base;
  typedef typename base::container_type           container_type;
  typedef typename container_type::iterator       iterator;
  typedef typename container_type::const_iterator const_iterator;

  iterator       begin() { return base::c.begin(); }
  const_iterator begin() const { return base::c.begin(); }
  iterator       end() { return base::c.end(); }
  const_iterator end() const { return base::c.end(); }
};

#endif