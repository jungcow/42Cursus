#include "Fixed.hpp"

#include <cmath>

const int Fixed::_fractionalBits = 8;

std::ostream &operator<<(std::ostream &C, const Fixed &F) {
  C << F.getRawBits() / 256.0f;
  return C;
}

Fixed::Fixed() {
  std::cout << "Default constructor called" << std::endl;
  _raw = 0;
}

Fixed::Fixed(const Fixed &other) {
  /*
	** 복사 생성자에서 대입 연산자 오버로딩한 것이 있으면 아래와 같이
	** 대입해서 바로 복사시켜 줄 수 있다.
	*/
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed::Fixed(const int integer) {
  std::cout << "Int constructor called" << std::endl;
  _raw = integer << _fractionalBits;
}

Fixed::Fixed(const float floatingPoint) {
  std::cout << "Float constructor called" << std::endl;
  _raw = roundf(floatingPoint * 256);
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Assignation operator called" << std::endl;
  _raw = other._raw;
  return *this;
}

int Fixed::getRawBits() const {
  // std::cout << "getRawBits member function called" << std::endl;
  return _raw;
}

void Fixed::setRawBits(int const raw) {
  // std::cout << "setRawBits member function called" << std::endl;
  _raw = raw;
}

float Fixed::toFloat() const {
  return (_raw / 256.0f);
}

int Fixed::toInt() const {
  return (_raw >> _fractionalBits);
}