//
// Created by yuumo on 2022/08/04.
//

#ifndef EX01_CONTACT_HPP
#define EX01_CONTACT_HPP

#include <iostream>

class Contact {
public:
	Contact();
	~Contact();

	void	copyContact(const Contact& contact);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickName() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	void	setFirstName(const std::string& firstName);
	void	setLaseName(const std::string& lastName);
	void	setNickName(const std::string& nickName);
	void	setPhoneNumber(const std::string& phoneNumber);
	void	setDarkestSecret(const std::string& darkestSecret);

private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phoneNumber;
	std::string _darkestSecret;

};


#endif //EX01_CONTACT_HPP
