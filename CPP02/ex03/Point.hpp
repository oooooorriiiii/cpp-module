//
// Created by yuumo on 2022/08/12.
//

#ifndef EX03_POINT_HPP
#define EX03_POINT_HPP

#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const float x, const float y);
	Point(const Fixed& x, const Fixed& y);
	Point(const Point& point);
	Point& operator=(const Point& point);
	~Point();

	Fixed getX() const;
	Fixed getY() const;

	void    setX(const Fixed x);
	void    setY(const Fixed y);

private:
	const Fixed _x;
	const Fixed _y;
};

Point operator-(const Point& a, const Point& b);

#endif //EX03_POINT_HPP
