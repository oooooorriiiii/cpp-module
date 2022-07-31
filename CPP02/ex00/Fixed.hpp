//
// Created by yuumo on 2022/07/31.
//

#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_fixedPointNumber;
	static const int	_fractionalBit;
public:
	Fixed();
	Fixed(const Fixed &copyFixed);
	Fixed& operator = (const Fixed &operatorFixed);
	~Fixed();

	/**
	 *
	 * @return
	 * the raw value of the fixed-point value
	 */
	int		getRawBits() const;
	/**
	 *
	 * @param raw
	 *
	 * sets the raw value of the fixed-point number
	 */
	void	setRawBits(int const raw);

};


#endif //EX00_FIXED_HPP
