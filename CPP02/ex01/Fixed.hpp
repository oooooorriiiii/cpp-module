//
// Created by yuumo on 2022/07/31.
//

#ifndef EX01_FIXED_HPP
#define EX01_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(int value);
	Fixed(float value);
	Fixed(const Fixed& copyFixed);
	Fixed& operator = (const Fixed &operatorFixed);
	~Fixed();

	/**
	 * @return
	 * the raw value of the fixed-point value
	 */
	int		getRawBits() const;

	/**
	 * sets the raw value of the fixed-point number
	 * @param raw
	 */
	void	setRawBits(int const raw);

	float toFloat() const ;
	int toInt() const ;

private:
	int					_fixedPointNumber;
	static const int	_fractionalBit;
};

std::ostream& operator<< (std::ostream &out, const Fixed& fixed);

#endif //EX01_FIXED_HPP
