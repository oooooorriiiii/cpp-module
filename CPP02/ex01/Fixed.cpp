//
// Created by yuumo on 2022/07/31.
//

#include "Fixed.hpp"

const int Fixed::_fractionalBit = 8;

/**
 * default constructor
 */
Fixed::Fixed() : _fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

/**
 * A constructor that takes a constant integer as a parameter.
 * It converts it to the corresponding fixed-point value.
 * Overflow is undefined.
 * @param value
 */
Fixed::Fixed(int value) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNumber = value * (1 << this->_fractionalBit);
}

/**
 * A constructor that takes a constant floating-point number as a parameter.
 * It converts it to the corresponding fixed-point value.
 * Overflow is undefined.
 * @param value
 */
Fixed::Fixed(float value) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNumber = roundf(value * (1 << this->_fractionalBit));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/**
 * copy constructor
 */
Fixed::Fixed(const Fixed &copyFixed) : _fixedPointNumber() {
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(copyFixed);
}

Fixed& Fixed::operator=(const Fixed &operatorFixed) {
	std::cout << "Copy assign operator called" << std::endl;
	this->_fixedPointNumber = operatorFixed.getRawBits();
	return *this;
}

/**
 * Inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.
 * @param out
 * @param fixed
 * @return
 */
std::ostream& operator<< (std::ostream &out, const Fixed& fixed) {
	return out << fixed.toFloat();
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNumber;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNumber = raw;
}

float Fixed::toFloat() const {
	double 	d = (double)(1 << _fractionalBit);
	return _fixedPointNumber / d;
}

int Fixed::toInt(void) const {
	return this->_fixedPointNumber >> _fractionalBit;
}