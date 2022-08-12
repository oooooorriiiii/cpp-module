//
// Created by yuumo on 2022/08/12.
//

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Fixed& x, const Fixed& y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point &point) : _x(Fixed(point._x)), _y(Fixed(point._y)) {}

Point &Point::operator=(const Point &point) {
	setX(point.getX());
	setY(point.getY());
	return *this;
}

Point::~Point() {}


/*
 * getters
 */

Fixed Point::getX() const {
	return _x;
}

Fixed Point::getY() const {
	return _y;
}


/*
 * Setters
 */

void    Point::setX(const Fixed x) {
	const_cast<Fixed &>(_x) = x;
}

void    Point::setY(const Fixed y) {
	const_cast<Fixed &>(_y) = y;
}


/*
 * Operator
 */

Point operator-(const Point& a, const Point& b) {
	return Point(a.getX() - b.getX(), a.getY() - b.getY());
}
