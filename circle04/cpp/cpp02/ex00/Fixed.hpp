#ifndef _FIXED_H__
#define _FIXED_H__

class Fixed {
 private:
  int _raw;
  static const int _fractionalBits;

 public:
  Fixed();
  Fixed(const Fixed& other);
  ~Fixed();
  Fixed& operator=(const Fixed& other);

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif