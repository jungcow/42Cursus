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

  float toFloat(void) const;
  int toInt(void) const;

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

std::ostream& operator<<(std::ostream& C, const Fixed& F);

#endif