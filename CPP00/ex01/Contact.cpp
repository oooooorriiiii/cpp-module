//
// Created by yuumo on 2022/08/04.
//

#include "Contact.hpp"

Contact::Contact() : _firstName("null"), _lastName("null"), _nickName("null"),
					 _phoneNumber("null"), _darkestSecret("null") {}

Contact::~Contact(){}

void	Contact::copyContact(const Contact& contact) {
	_firstName = contact.getFirstName();
	_lastName = contact.getLastName();
	_nickName = contact.getNickName();
	_phoneNumber = contact.getPhoneNumber();
	_darkestSecret = contact.getDarkestSecret();
}

/*
 * Getters
 */

std::string Contact::getFirstName() const {
	return _firstName;
}

std::string Contact::getLastName() const {
	return _lastName;
}

std::string Contact::getNickName() const {
	return _nickName;
}

std::string Contact::getPhoneNumber() const {
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
	return _darkestSecret;
}


/*
 * Setters
 */

void Contact::setFirstName(const std::string& firstName) {
	_firstName = firstName;
}

void Contact::setLaseName(const std::string& lastName) {
	_lastName = lastName;
}

void Contact::setNickName(const std::string& nickName) {
	_nickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
	_darkestSecret = darkestSecret;
}
