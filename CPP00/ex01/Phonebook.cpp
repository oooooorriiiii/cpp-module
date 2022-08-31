#include <cstdlib>

#include "Phonebook.hpp"

Phonebook::Phonebook() : _fullIndex(0), _index(0){}

Phonebook::~Phonebook() {}

void Phonebook::inputHandler(int index) {
	std::string	inputString;

	std::cout << "First Name : ";
	if (std::cin >> inputString) {
		_contacts[index].setFirstName(inputString);
	} else {
		std::cout << std::endl;
		exit(1);
	}
	std::cout << "Last Name : ";
	if (std::cin >> inputString) {
		_contacts[index].setLaseName(inputString);
	} else {
		std::cout << std::endl;
		exit(1);
	}
	std::cout << "Nickname : ";
	if (std::cin >> inputString) {
		_contacts[index].setNickName(inputString);
	} else {
		std::cout << std::endl;
		exit(1);
	}
	std::cout << "Phone Number : ";
	if (std::cin >> inputString) {
		_contacts[index].setPhoneNumber(inputString);
	} else {
		std::cout << std::endl;
		exit(1);
	}
	std::cout << "Darkest Secret : ";
	if (std::cin >> inputString) {
		_contacts[index].setDarkestSecret(inputString);
	} else {
		std::cout << std::endl;
		exit(1);
	}
}

void Phonebook::addContact() {

    if (_fullIndex < 8) {
		inputHandler(_fullIndex);
        ++_fullIndex;
    } else {
        if (_index == 8)
			_index = 0;
		inputHandler(_index);
		++_index;
	}
}

std::string Phonebook::fmtContact(std::string str) {
    if (str.length() <= 10) {
        return str;
    }
    str = str.substr(0, 9);
    str.append(".");
    return str;
}

void Phonebook::showContactTable(void) {
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    for (int i = 0; i < _fullIndex; ++i) {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << fmtContact(_contacts[i].getFirstName());
        std::cout << "|" << std::setw(10) << fmtContact(_contacts[i].getLastName());
        std::cout << "|" << std::setw(10) << fmtContact(_contacts[i].getNickName());
        std::cout << "|" << std::endl;
    }
    std::cout << "|-------------------------------------------|" << std::endl;
}

void Phonebook::search(void) {
    int target_index;

    std::cout << "search index : ";
    std::cin >> target_index;
    std::cin.ignore();
	if (std::cin.eof())
	{
		std::cout << std::endl;
		exit(1);
	}
    if (std::cin.fail()) {
        std::cout << "Invalid index" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }
    if (target_index >= _fullIndex || target_index < 0) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    std::cout << "First Name : " << _contacts[target_index].getFirstName() << std::endl;
    std::cout << "Last Name : " << _contacts[target_index].getLastName() << std::endl;
    std::cout << "Nickname : " << _contacts[target_index].getNickName() << std::endl;
    std::cout << "Phone Number : " << _contacts[target_index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << _contacts[target_index].getDarkestSecret() << std::endl;
}
