//
// Created by yuumo on 2022/07/31.
//

#include "Fixed.hpp"

const int Fixed::_fractionalBit = 8;

Fixed::Fixed() : _fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copyFixed) : _fixedPointNumber() {
	std::cout << "Copy constructor called" << std::endl;
	this->operator=(copyFixed);
}

Fixed& Fixed::operator=(const Fixed &operatorFixed) {
	std::cout << "Copy assign operator called" << std::endl;
	this->_fixedPointNumber = operatorFixed.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointNumber;
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointNumber = raw;
}