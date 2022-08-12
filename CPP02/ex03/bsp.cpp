//
// Created by yuumo on 2022/08/12.
//

#include "Fixed.hpp"
#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point) {

	Point ab = b - a;
	Point bp = point - b;

	Point bc = c - b;
	Point cp = point - c;

	Point ca = a - c;
	Point ap = point - a;

	// z component of cross product
	Fixed c1 = ab.getX() * bp.getY() - ab.getY() * bp.getX();
	Fixed c2 = bc.getX() * cp.getY() - bc.getY() * cp.getX();
	Fixed c3 = ca.getX() * ap.getY() - ca.getY() * ap.getX();

	if ((c1 > 0 && c2 > 0 && c3 > 0) || (c1 < 0 && c2 < 0 && c3 < 0)) {
		return true;
	}
	return false;
}