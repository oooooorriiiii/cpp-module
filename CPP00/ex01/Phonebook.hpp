#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

#include "Contact.hpp"

class Phonebook {
public:
	Phonebook();
	~Phonebook();
	void addContact(void);
	void showContactTable(void);
	void search(void);

private:
	Contact					_contacts[8];
    int                     _fullIndex;
    int                     _index;
    std::string fmtContact(std::string str);
};

#endif