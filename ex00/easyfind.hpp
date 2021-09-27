#ifndef _EASYFIND_H__
#define _EASYFIND_H__

#include <algorithm>
#include <iostream>

template <typename T> typename T::iterator easyfind(T &container, int n) {
  return (std::find(container.begin(), container.end(), n));
}

#endif
