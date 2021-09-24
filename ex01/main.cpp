#include "iter.hpp"

int main(void) {
  {
    int         i[3] = {1, 2, 3};
    double      d[3] = {1.1, 2.2, 3.3};
    std::string str[3] = {"hihi", "hello", "world"};

    iter(i, sizeof(i) / sizeof(i[0]), print);
    iter(d, sizeof(d) / sizeof(d[0]), print);
    iter(str, sizeof(str) / sizeof(str[0]), print);
    iter(i, -2, print);
  }

  {
    int     tab[] = {0, 1, 2, 3, 4};
    Awesome tab2[5];
    iter(tab, 5, print);
    iter(tab2, 5, print);
  }
  return 0;
}
