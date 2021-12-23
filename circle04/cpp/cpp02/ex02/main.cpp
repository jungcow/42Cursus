#include "Fixed.hpp"
int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max(a, b) << std::endl;
  std::cout << Fixed::min(a, b) << std::endl;

  std::cout << "\na + b: " << a + b << std::endl;
  std::cout << "a - b: " << a - b << std::endl;
  std::cout << "a / b: " << a / b << std::endl;
  std::cout << "a * b: " << a * b << std::endl;

  std::cout << "\na >= b: " << (a >= b) << std::endl;
  std::cout << "a <= b: " << (a <= b) << std::endl;
  std::cout << "a == b: " << (a == b) << std::endl;
  std::cout << "a != b: " << (a != b) << std::endl;

  Fixed c;

  c = b + a / b + b;
  std::cout << "c: " << c << std::endl;

  std::cout << "\n";
  std::cout << a << std::endl;
  std::cout << --a << std::endl;
  std::cout << a << std::endl;
  std::cout << a-- << std::endl;
  std::cout << a << std::endl;

  std::cout << a + b << "\n"
            << (a + b < 11) << std::endl;
  return 0;
}