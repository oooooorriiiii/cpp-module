//
// Created by yuumo on 2022/07/31.
//

#include "Fixed.hpp"

const int Fixed::_fractionalBit = 8;

/**
 * default constructor
 */
Fixed::Fixed() : _fixedPointNumber(0) {
//	std::cout << "Default constructor called" << std::endl;
}

/**
 * A constructor that takes a constant integer as a parameter.
 * It converts it to the corresponding fixed-point value.
 * Overflow is undefined.
 * @param value
 */
Fixed::Fixed(int value) {
//	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointNumber = value * (1 << this->_fractionalBit);
}

/**
 * A constructor that takes a constant floating-point number as a parameter.
 * It converts it to the corresponding fixed-point value.
 * Overflow is undefined.
 * @param value
 */
Fixed::Fixed(float value) {
//	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointNumber = roundf(value * (1 << this->_fractionalBit));
}

Fixed::~Fixed() {
//	std::cout << "Destructor called" << std::endl;
}

/**
 * copy constructor
 */
Fixed::Fixed(const Fixed &copyFixed) : _fixedPointNumber() {
//	std::cout << "Copy constructor called" << std::endl;
	this->operator=(copyFixed);
}

Fixed& Fixed::operator=(const Fixed &operatorFixed) {
//	std::cout << "Copy assign operator called" << std::endl;
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
//	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNumber;
}

void Fixed::setRawBits(const int raw) {
//	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNumber = raw;
}

float Fixed::toFloat() const {
	double 	d = (double)(1 << _fractionalBit);
	return _fixedPointNumber / d;
}

int Fixed::toInt(void) const {
	return this->_fixedPointNumber >> _fractionalBit;
}



/*
 * Comparison operators
 */

bool Fixed::operator>(const Fixed& rightValue) const {
	return this->getRawBits() > rightValue.getRawBits();
}

bool Fixed::operator>=(const Fixed& rightValue) const {
	return this->getRawBits() >= rightValue.getRawBits();
}

bool Fixed::operator<(const Fixed& rightValue) const {
	return this->getRawBits() < rightValue.getRawBits();
}

bool Fixed::operator<=(const Fixed& rightValue) const {
	return this->getRawBits() <= rightValue.getRawBits();
}

bool Fixed::operator==(const Fixed& rightValue) const {
	return this->getRawBits() == rightValue.getRawBits();
}

bool Fixed::operator!=(const Fixed& rightValue) const {
	return this->getRawBits() != rightValue.getRawBits();
}

/*
 * Arithmetic operators
 */

Fixed	Fixed::operator+(const Fixed &rightValue) {
	Fixed	sum(*this);
	sum.setRawBits(this->getRawBits() + rightValue.getRawBits());
	return sum;
}

Fixed	Fixed::operator-(const Fixed &rightValue) {
	Fixed	difference(*this);
	difference.setRawBits(this->getRawBits() - rightValue.getRawBits());
	return difference;
}

Fixed	Fixed::operator*(const Fixed &rightValue) {
	Fixed	product(*this);
	product.setRawBits(this->getRawBits() * rightValue.getRawBits() / (1 << _fractionalBit));
	return product;
}

/**
 * dividing by zero is undefined
 * @param rightValue
 * @return
 */
Fixed	Fixed::operator/(const Fixed &rightValue) {
	Fixed	quotient(*this);
	quotient.setRawBits(this->getRawBits() * (1 << _fractionalBit) / rightValue.getRawBits());
	return quotient;
}

/*
 * Increment / Decrement
 */

/**
 * pre-increment
 * @return
 */
Fixed&	Fixed::operator++() {
	this->_fixedPointNumber++;
	return *this;
}

/**
 * pre-decrement
 * @return
 */
Fixed&	Fixed::operator--() {
	this->_fixedPointNumber--;
	return *this;
}

/**
 * post-increment
 * @return
 */
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(this->_fixedPointNumber);
	return tmp;
}

/**
 * post-decrement
 * @return
 */
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(this->_fixedPointNumber);
	return tmp;
}

/*
 * Other functions
 */

Fixed&	Fixed::min(Fixed &value1, Fixed &value2) {
	return (value1 < value2) ? value1 : value2;
}

const Fixed&	Fixed::min(const Fixed &value1, const Fixed &value2) {
	return (value1 < value2) ? value1 : value2;
}
Fixed&	Fixed::max(Fixed &value1, Fixed &value2) {
	return (value1 > value2) ? value1 : value2;
}

const Fixed&	Fixed::max(const Fixed &value1, const Fixed &value2) {
	return (value1 > value2) ? value1 : value2;
}
