//
// Created by yuumo on 2022/07/29.
//

#include "Fixed.hpp"

int	main()
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "a is " << a.toFloat() << " as float" << std::endl;
	std::cout << "b is " << b.toFloat() << " as float" << std::endl;
	std::cout << "c is " << c.toFloat() << " as float" << std::endl;
	std::cout << "d is " << d.toFloat() << " as float" << std::endl;

	// The fixed-point is fixed to 8 bits.
	// MAX (2e+23 - 1) ~ MIN (-2e+23)
	Fixed const e(8388607);
	Fixed const f( -8388608);

	std::cout << "e is " << e.toInt() << " as Int" << std::endl;
	std::cout << "f is " << f.toInt() << " as Int" << std::endl;

	std::cout << "e is " << e.toFloat() << " as float" << std::endl;
	std::cout << "f is " << f.toFloat() << " as float" << std::endl;

	// Precision
	// 0.99609375 =
	// (2^(-1))+(2^(-2))+(2^(-3))+(2^(-4))+(2^(-5))+(2^(-6))+(2^(-7))+(2^(-8))
	Fixed const g(0.99609375f);
	Fixed const h( -0.99609375f);

	std::cout << "g is " << g.toInt() << " as Int" << std::endl;
	std::cout << "h is " << h.toInt() << " as Int" << std::endl;

	std::cout << "g is " << g.toFloat() << " as float" << std::endl;
	std::cout << "h is " << h.toFloat() << " as float" << std::endl;

	return 0;
}