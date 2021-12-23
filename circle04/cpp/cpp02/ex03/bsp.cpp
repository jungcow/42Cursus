#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Point u = b - a;
  Point v = c - a;
  Point w = point - a;
  /*
** 분모가 0이 되면 안되므로 우선 예외처를 해준다.
*/
  if (Point::dotVector(u, u) * Point::dotVector(v, v) == Point::dotVector(u, v) * Point::dotVector(v, u))
    return (false);

  Fixed s = ((Point::dotVector(v, v) * Point::dotVector(w, u)) - (Point::dotVector(v, u) * Point::dotVector(w, v))) / ((Point::dotVector(u, u) * Point::dotVector(v, v)) - (Point::dotVector(u, v) * Point::dotVector(v, u)));
  Fixed t = ((Point::dotVector(u, u) * Point::dotVector(w, v)) - Point::dotVector(u, v) * Point::dotVector(w, u)) / ((Point::dotVector(u, u) * Point::dotVector(v, v)) - (Point::dotVector(u, v) * Point::dotVector(v, u)));
  if (s > Fixed(0) && t > Fixed(0) && s + t < 1)
    return (true);
  return (false);
}