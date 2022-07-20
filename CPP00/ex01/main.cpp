#include "phonebook.hpp"

int main() {
    std::string cmd;
    Phonebook   phonebook;

    while (true) {
        std::cout << "Please your command [EXIT, ADD, SEARCH]" << std::endl << ">";
        std::cin >> cmd;

        if (cmd.compare("ADD") == 0){
            phonebook.Add_contact();
        } else if (cmd.compare("SEARCH") == 0) {
            phonebook.Show_contact_table();
            phonebook.Search();
        } else if (cmd.compare("EXIT") == 0) {
            break;
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }
    return 0;
}