#ifndef _POINT_H__
#define _POINT_H__

#include "Fixed.hpp"

class Point {
 private:
  Fixed const x;
  Fixed const y;

 public:
  Point() : x(0), y(0) {}
  Point(const Point &other) : x(other.x), y(other.y) {}
  Point(const Fixed &ax, const Fixed &ay) : x(ax), y(ay) {}
  ~Point() {}

  Point &operator=(const Point &other);
  const Point operator+(const Point &other) const;
  const Point operator-(const Point &other) const;
  // const Point operator*(const Point &other) const;
  // const Point operator/(const Point &other) const;

  static const Fixed dotVector(const Point &a, const Point &b);

  const Fixed &getX(void) const;
  const Fixed &getY(void) const;
};

std::ostream &operator <<(std::ostream &c, const Point &point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif