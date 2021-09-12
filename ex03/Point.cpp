#include "Point.hpp"

Point &Point::operator=(const Point &other) {
  /*
	** const_cast 연산자는 포인터의 상수성만 비상수성으로 바꿔줄 수 있는데
	** 아래와 같이 주소 연산자를 붙여주어 꼼수를 써서 할 수도 있다.
	*/
  *const_cast<Fixed *>(&x) = other.x;
  *const_cast<Fixed *>(&y) = other.y;
  return *this;
}

const Point Point::operator+(const Point &other) const {
  return Point(x + other.x, y + other.y);
}

const Point Point::operator-(const Point &other) const {
  return Point(x - other.x, y - other.y);
}

// const Point Point::operator*(const Point &other) const {
//   return Point(x * other.x, y * other.y);
// }

// const Point Point::operator/(const Point &other) const {
//   return Point(x / other.x, y / other.y);
// }

const Fixed Point::dotVector(const Point &a, const Point &b) {
  return (Fixed((a.x * b.x) + (a.y * b.y)));
}

const Fixed &Point::getX() const {
  return x;
}
const Fixed &Point::getY() const {
  return y;
}

std::ostream &operator<<(std::ostream &c, const Point &point) {
  c << "x: " << point.getX() << " y: " << point.getY();
  return c;
}
