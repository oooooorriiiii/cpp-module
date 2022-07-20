#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

class Phonebook {
private:
    struct phonebook_data {
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    };

    struct phonebook_data   info[8];
    int                     full_index;
    int                     index;
    std::string fmt_contact(std::string str);

public:
    Phonebook();
    ~Phonebook();
    void Add_contact(void);
    void Show_contact_table(void);
    void Search(void);
};

#endif