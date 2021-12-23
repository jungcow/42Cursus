#include "Fixed.hpp"

/*
** << 연산자 오버로딩 및 변환생성자 추가
*/

int main(void) {
  Fixed a;
  Fixed const b(10);
  Fixed const c(42.42f);
  Fixed const d(b);

  a = Fixed(1234.4321f);

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.toInt() << " as integer" << std::endl;
  std::cout << "b is " << b.toInt() << " as integer" << std::endl;
  std::cout << "c is " << c.toInt() << " as integer" << std::endl;
  std::cout << "d is " << d.toInt() << " as integer" << std::endl;

  /*
  ** 암시적인 형변환
  */
  Fixed e = 3.38f; 
  std::cout << "e is " << e << std::endl;

  /*
  ** 명시적인 형변환
  */
  Fixed f(1000);
  std::cout << "f is " << f << std::endl;
  return 0;
}