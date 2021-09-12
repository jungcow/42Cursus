#include "Point.hpp"

int main(void) {
  Point a(Fixed(0), Fixed(0));
  Point b(Fixed(10), Fixed(5));
  Point c(Fixed(10), Fixed(5));

  Point point(Fixed(4), Fixed(1));

  std::cout << bsp(a, b, c, point) << std::endl;
}