//
// Created by yuumo on 2022/07/31.
//

#ifndef EX02_FIXED_HPP
#define EX02_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed();
	Fixed(int value);
	Fixed(float value);
	Fixed(const Fixed& copyFixed);
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

	float	toFloat() const ;
	int 	toInt() const ;

	Fixed& operator = (const Fixed &operatorFixed);

	bool	operator>(const Fixed &rightValue) const;
	bool	operator>=(const Fixed &rightValue) const;
	bool	operator<(const Fixed &rightValue) const;
	bool	operator<=(const Fixed &rightValue) const;
	bool	operator==(const Fixed &rightValue) const;
	bool	operator!=(const Fixed &rightValue) const;

	Fixed	operator+(const Fixed &rightValue);
	Fixed	operator-(const Fixed &rightValue);
	Fixed	operator*(const Fixed &rightValue);
	Fixed	operator/(const Fixed &rightValue);

	Fixed&	operator++();
	Fixed&	operator--();
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed&			min(Fixed& value1, Fixed& value2);
	static const Fixed&	min(const Fixed& value1, const Fixed& value2);
	static Fixed&			max(Fixed& value1, Fixed& value2);
	static const Fixed&	max(const Fixed& value1, const Fixed& value2);


private:
	int					_fixedPointNumber;
	static const int	_fractionalBit;
};

std::ostream& operator<< (std::ostream &out, const Fixed& fixed);

#endif //EX02_FIXED_HPP
