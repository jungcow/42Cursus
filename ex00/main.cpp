#include "easyfind.hpp"

int main(void) {
  int arr[] = {1, 2, 3, 4, 5};
  /*
  ** vector 컨테이너
  */
  std::vector<int>           vect(arr, arr + (sizeof(arr) / sizeof(int)));
  std::vector<int>::iterator vi = vect.end();
  std::cout << "[ vector Container ] ";
  easyfind(vect, 6) != vi ? std::cout << "I found it!\n"
                          : std::cout << "Not Found\n";

  /*
  ** list 컨테이너
  */
  std::list<int>           li(arr, arr + (sizeof(arr) / sizeof(int)));
  std::list<int>::iterator it = li.end();
  std::cout << "[ list Container ] ";
  easyfind(li, 1) != it ? std::cout << "I found it!\n"
                        : std::cout << "Not Found\n";

  /*
  ** set 컨테이너
  */
  std::set<int>           se(arr, arr + (sizeof(arr) / sizeof(int)));
  std::set<int>::iterator si = se.end();
  std::cout << "[ set Container ] ";
  easyfind(se, 4) != si ? std::cout << "I found it!\n"
                        : std::cout << "Not Found\n";

  return (0);
}
