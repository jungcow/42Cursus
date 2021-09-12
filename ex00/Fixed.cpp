#include "Fixed.hpp"

#include <iostream>

const int Fixed::_fractionalBits = 8;

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

Fixed::~Fixed() {
  std::cout << "Destructor Called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Assignation operator called" << std::endl;
  _raw = other._raw;
  return *this;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return _raw;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  _raw = raw;
}