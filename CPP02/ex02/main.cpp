//
// Created by yuumo on 2022/07/29.
//

#include "Fixed.hpp"

int main( void ) {

	// Subject test case
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	// test
	std::cout << "****************" << std::endl;
	std::cout << "a is "<< a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << --a << std::endl;
	std::cout << "a is "<< a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a-- << std::endl;
	std::cout << "a is "<< a << std::endl;
	std::cout << "****************" << std::endl;

	std::cout << "****************" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "max is " << Fixed::max( a, b ) << std::endl;
	std::cout << "min is " << Fixed::min( a, b ) << std::endl;
	std::cout << "****************" << std::endl;

	std::cout << "****************" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout  << a + b << std::endl;
	std::cout  << a - b << std::endl;
	std::cout  << a * b << std::endl;
	std::cout  << a / b << std::endl;
	std::cout << "****************" << std::endl;

	std::cout << "****************" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout  << (a > b)<< std::endl;
	std::cout  << (a >= b) << std::endl;
	std::cout  << (a < b)<< std::endl;
	std::cout  << (a <= b) << std::endl;
	std::cout  << (a == b) << std::endl;
	std::cout  << (a != b) << std::endl;
	std::cout << "****************" << std::endl;

//	std::cout << "a is " << a << std::endl;
//	std::cout << "b is " << b << std::endl;

	return 0;

}