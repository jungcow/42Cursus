#ifndef _FIXED_H__
#define _FIXED_H__

#include <iostream>

class Fixed {
 private:
  int _raw;
  static const int _fractionalBits;

 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed(const int integer);
  Fixed(const float floatingPoint);
  ~Fixed();

  Fixed& operator=(const Fixed& other);

/*
** 정수와 Fixed 객체의 사칙연산을 만들지 않은 이유:
** 정수를 더할 때, raw에 더할지, 아니면 원래 수에 더할지 애매모호하기 때문이다.
** 프로그래밍에서 애매모호함은 곧 해선 안되는 것
** 따라서 정수형과의 사칙연산은 아예 정의조차 하지 않았다.
*/
  const Fixed operator+(const Fixed& other) const;
  const Fixed operator-(const Fixed& other) const;
  const Fixed operator*(const Fixed& other) const;
  const Fixed operator/(const Fixed& other) const;

  bool operator>(const Fixed& other) const;
  bool operator<(const Fixed& other) const;
  bool operator>=(const Fixed& other) const;
  bool operator<=(const Fixed& other) const;
  bool operator==(const Fixed& other) const;
  bool operator!=(const Fixed& other) const;

  Fixed& operator++(void);
  const Fixed operator++(int);
  Fixed& operator--(void);
  const Fixed operator--(int);

  static const Fixed& min(Fixed& a, Fixed& b);
  static const Fixed& min(const Fixed& a, const Fixed& b);
  static const Fixed& max(Fixed& a, Fixed& b);
  static const Fixed& max(const Fixed& a, const Fixed& b);

  float toFloat(void) const;
  int toInt(void) const;

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& C, const Fixed& F);

#endif