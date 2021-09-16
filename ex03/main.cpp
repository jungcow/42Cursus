#include "Point.hpp"

int main(void) {
  int x_min, x_max, y_min, y_max;
  x_min = 0;
  y_min = 0;
  x_max = 50;
  y_max = 50;
  Point a((Fixed(x_min)), Fixed(y_min));
  Point b((Fixed(x_max / 2)), Fixed(y_max));
  Point c((Fixed(x_max)), Fixed(y_min));

  Point point1(Fixed(8), Fixed(0));
  Point point2(Fixed(8), Fixed(1));
  Point point3(Fixed(8), Fixed(2));
  Point point4(Fixed(8), Fixed(3));
  Point point5(Fixed(8), Fixed(4));

  std::cout << bsp(a, b, c, point1) << std::endl;
  std::cout << bsp(a, b, c, point2) << std::endl;
  std::cout << bsp(a, b, c, point3) << std::endl;
  std::cout << bsp(a, b, c, point4) << std::endl;
  std::cout << bsp(a, b, c, point5) << std::endl;

  for (int y = y_max; y >= y_min; y--) {
    for (int x = x_min; x <= x_max; x++) {
      Point point((Fixed(x)), (Fixed(y)));
      if (bsp(a, b, c, point)) {
        std::cout << "$";
      } else
        std::cout << ".";
    }
    std::cout << std::endl;
  }
}