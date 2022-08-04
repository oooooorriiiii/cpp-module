#include "Phonebook.hpp"

Phonebook::Phonebook() : _fullIndex(0), _index(0){}

Phonebook::~Phonebook() {}

void Phonebook::addContact() {
	std::string	inputString;

    if (_fullIndex < 8) {
        std::cout << "First Name : ";
        std::cin >> inputString;
		_contacts[_fullIndex].setFirstName(inputString);
        std::cout << "Last Name : ";
		std::cin >> inputString;
		_contacts[_fullIndex].setLaseName(inputString);
        std::cout << "Nickname : ";
		std::cin >> inputString;
		_contacts[_fullIndex].setNickName(inputString);
        std::cout << "Phone Number : ";
		std::cin >> inputString;
		_contacts[_fullIndex].setPhoneNumber(inputString);
        std::cout << "Darkest Secret : ";
		std::cin >> inputString;
		_contacts[_fullIndex].setDarkestSecret(inputString);
        ++_fullIndex;
    } else {
        if (_index == 8)
			_index = 0;
		std::cout << "First Name : ";
		std::cin >> inputString;
		_contacts[_index].setFirstName(inputString);
		std::cout << "Last Name : ";
		std::cin >> inputString;
		_contacts[_index].setLaseName(inputString);
		std::cout << "Nickname : ";
		std::cin >> inputString;
		_contacts[_index].setNickName(inputString);
		std::cout << "Phone Number : ";
		std::cin >> inputString;
		_contacts[_index].setPhoneNumber(inputString);
		std::cout << "Darkest Secret : ";
		std::cin >> inputString;
		_contacts[_index].setDarkestSecret(inputString);
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
