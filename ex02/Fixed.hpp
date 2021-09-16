#ifndef _FIXED_H__
#define _FIXED_H__

#include <iostream>

class Fixed {
private:
  int              _raw;
  static const int _fractionalBits;

public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed(const int integer);
  Fixed(const float floatingPoint);
  ~Fixed();

  Fixed &operator=(const Fixed &other);

  /*
  ** 정수와 Fixed 객체의 사칙연산을 만들지 않은 이유:
  ** 정수를 더할 때, raw에 더할지, 아니면 원래 수에 더할지 애매모호하기
  ** 때문이다.
  ** 프로그래밍에서 애매모호함은 곧 해선 안되는 것
  ** 따라서 정수형과의 사칙연산은 아예 정의조차 하지 않았다.
  */
  const Fixed operator+(const Fixed &other) const;
  const Fixed operator-(const Fixed &other) const;
  const Fixed operator*(const Fixed &other) const;
  const Fixed operator/(const Fixed &other) const;

  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  Fixed &     operator++(void);
  const Fixed operator++(int);
  Fixed &     operator--(void);
  const Fixed operator--(int);

  /*
  ** static function member에서는 const형 함수를 지정할 수 없는데
  ** 그 이유는, const 형 함수는 this에 영향을 미치는 한정자이기 때문이다.
  ** 즉, const를 붙임으로써 this객체를 변경할 수 없도록 하는 것인데,
  ** static 멤버 함수는 인자로 this가 들어가지 않는다. -> 왜냐면 static으로 
  ** 지정한 것을 클래스 소유인 것이지, 객체 소유가 아니기 때문!
  */
  static Fixed &      min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &      max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

  float toFloat(void) const;
  int   toInt(void) const;

  int  getRawBits(void) const;
  void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &C, const Fixed &F);

#endif