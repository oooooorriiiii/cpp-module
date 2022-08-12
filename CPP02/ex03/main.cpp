//
// Created by yuumo on 2022/07/29.
//

#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"

bool    bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	{
		Point a(4, 4);
		Point b(0, 4);
		Point c(4, 12);

		std::cout << "false: point of the boundary" << std::endl;
		std::cout << bsp(a, b, c, a) << std::endl;
		std::cout << bsp(a, b, c, Point(0,4)) << std::endl; // b
		std::cout << bsp(a, b, c, Point(0.5,5)) << std::endl;
		std::cout << bsp(a, b, c, Point(4,12)) << std::endl; // c

		std::cout << "false: point outside the area" << std::endl;
		std::cout << bsp(a, b, c, Point(0,5)) << std::endl;
		std::cout << bsp(a, b, c, Point(2,0)) << std::endl;

		std::cout << "true: point inside the area" << std::endl;
		std::cout << bsp(a, b, c, Point(1,5)) << std::endl;
		std::cout << bsp(a, b, c, Point(2,6)) << std::endl;
		std::cout << bsp(a, b, c, Point(2,6.5)) << std::endl;
		std::cout << bsp(a, b, c, Point(2,7)) << std::endl;
	}

	return 0;

}