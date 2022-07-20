#include "phonebook.hpp"

Phonebook::Phonebook(void) {
    full_index = 0;
    index = 0;
}

Phonebook::~Phonebook(void) {
}

void Phonebook::Add_contact(void) {
    if (full_index < 8) {
        std::cout << "First Name : ";
        std::cin >> info[full_index].first_name;
        std::cout << "Last Name : ";
        std::cin >> info[full_index].last_name;
        std::cout << "Nickname : ";
        std::cin >> info[full_index].nickname;
        std::cout << "Phone Number : ";
        std::cin >> info[full_index].phone_number;
        std::cout << "Darkest Secret : ";
        std::cin >> info[full_index].darkest_secret;
        ++full_index;
    } else {
        if (index == 8)
            index = 0;
        std::cout << "First Name : ";
        std::cin >> info[index].first_name;
        std::cout << "Last Name : ";
        std::cin >> info[index].last_name;
        std::cout << "Nickname : ";
        std::cin >> info[index].nickname;
        std::cout << "Phone Number : ";
        std::cin >> info[index].phone_number;
        std::cout << "Darkest Secret : ";
        std::cin >> info[index].darkest_secret;
        ++index;
    }
}

std::string Phonebook::fmt_contact(std::string str) {
    if (str.length() <= 10) {
        return str;
    }
    str = str.substr(0, 9);
    str.append(".");
    return str;
}

void Phonebook::Show_contact_table(void) {
    std::cout << "|-------------------------------------------|" << std::endl;
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
    for (int i = 0; i < full_index; ++i) {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << fmt_contact(info[i].first_name);
        std::cout << "|" << std::setw(10) << fmt_contact(info[i].last_name);
        std::cout << "|" << std::setw(10) << fmt_contact(info[i].nickname);
        std::cout << "|" << std::endl;
    }
    std::cout << "|-------------------------------------------|" << std::endl;
}

void Phonebook::Search(void) {
    int target_index;

    std::cout << "Search index : ";
    std::cin >> target_index;
    std::cin.ignore();
    if (std::cin.fail()) {
        std::cout << "Invalid index" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return ;
    }
    if (target_index >= full_index || target_index < 0) {
        std::cout << "Invalid index" << std::endl;
        return ;
    }
    std::cout << "First Name : " << info[target_index].first_name << std::endl;
    std::cout << "Last Name : " << info[target_index].last_name << std::endl;
    std::cout << "Nickname : " << info[target_index].nickname << std::endl;
    std::cout << "Phone Number : " << info[target_index].phone_number << std::endl;
    std::cout << "Darkest Secret : " << info[target_index].darkest_secret << std::endl;
}
