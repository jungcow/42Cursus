#include "easyfind.hpp"

int main(void) {
  int         arr[] = {1, 2, 3, 4, 5};
  std::vector<int> vi(arr, arr + (sizeof(arr) / sizeof(int)));
  std::list<int>   li(arr, arr + (sizeof(arr) / sizeof(int)));
  /*
  ** vector 컨테이너
  */
  easyfind(vi, 6) ? std::cout << "I found it!\n" : std::cout << "Not Found\n";

  /*
  ** list 컨테이너
  */
  easyfind(li, 1) ? std::cout << "I found it!\n" : std::cout << "Not Found\n";
  return (0);
}
