#ifndef _EASYFIND_H__
#define _EASYFIND_H__

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

template <typename T> unsigned int easyfind(T &container, int n) {

  if (std::find(container.begin(), container.end(), n) == container.end()) {
    return (0);
  }
  return (1);
}

#endif
