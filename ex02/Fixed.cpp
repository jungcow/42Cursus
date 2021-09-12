#include "Fixed.hpp"

#include <cmath>

const int Fixed::_fractionalBits = 8;

/*
** min, max 함수
*/
const Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return (a > b ? b : a);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a > b ? b : a);
}

const Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b ? a : b);
}

/*
** 출력 스트림을 전역 연산자 함수로 오버로딩
*/
std::ostream &operator<<(std::ostream &C, const Fixed &F) {
  C << (F.getRawBits() / 256.0f);
  return C;
}

/*
** 생성자, 파괴자
*/
Fixed::Fixed() {
  _raw = 0;
}
Fixed::Fixed(const Fixed &other) {
  /*
	** 복사 생성자에서, 대입 연산자 오버로딩한 것이 있으면 아래와 같이
	** 대입해서 바로 복사시켜 줄 수 있다.
	*/
  *this = other;
}
Fixed::Fixed(const int integer) {
  _raw = integer << _fractionalBits;
}
Fixed::Fixed(const float floatingPoint) {
  _raw = roundf(floatingPoint * 256);
}
Fixed::~Fixed() {
}

/*************************************\
************ 연산자 오버로딩 **************
\*************************************/

/*
** 대입 연산자 오버로딩
*/
Fixed &Fixed::operator=(const Fixed &other) {
  _raw = other._raw;
  return *this;
}

/*
** 사칙 연산자 오버로딩
*/
const Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed((_raw / 256.0f) + (other._raw / 256.0f));
}

const Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed((_raw / 256.0f) - (other._raw / 256.0f));
}

const Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed((_raw / 256.0f) * (other._raw / 256.0f));
}

const Fixed Fixed::operator/(const Fixed &other) const {
  return Fixed((_raw / 256.0f) / (other._raw / 256.0f));
}

/* 
** 비교 연산자 오버로딩
*/
bool Fixed::operator>(const Fixed &other) const {
  return (_raw > other._raw ? true : false);
}

bool Fixed::operator<(const Fixed &other) const {
  return (_raw < other._raw ? true : false);
}

bool Fixed::operator>=(const Fixed &other) const {
  return (_raw >= other._raw ? true : false);
}

bool Fixed::operator<=(const Fixed &other) const {
  return (_raw <= other._raw ? true : false);
}

bool Fixed::operator==(const Fixed &other) const {
  return (_raw == other._raw ? true : false);
}

bool Fixed::operator!=(const Fixed &other) const {
  return (*this == other ? false : true);
}

/*
** 증감 연산자 오버로딩
*/
Fixed &Fixed::operator++() {
  _raw++;
  return *this;
}

const Fixed Fixed::operator++(int) {
  Fixed fixed = *this;
  _raw++;
  return fixed;
}

Fixed &Fixed::operator--() {
  _raw--;
  return *this;
}

const Fixed Fixed::operator--(int) {
  Fixed fixed = *this;
  _raw--;
  return fixed;
}

/*
** 변환 함수
*/
float Fixed::toFloat() const {
  return (_raw / 256.0f);
}

int Fixed::toInt() const {
  return (_raw >> _fractionalBits);
}

/*
** Getter, Setter
*/
int Fixed::getRawBits() const {
  return _raw;
}

void Fixed::setRawBits(int const raw) {
  _raw = raw;
}
