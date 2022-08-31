#include <cstdlib>
#include "Phonebook.hpp"

int main() {
    std::string cmd;
    Phonebook   phonebook;

    while (true) {
        std::cout << "Please your command [EXIT, ADD, SEARCH]" << std::endl << ">";

		if (std::cin >> cmd) {
			if (cmd == "ADD"){
				phonebook.addContact();
			} else if (cmd == "SEARCH") {
				phonebook.showContactTable();
				phonebook.search();
			} else if (cmd == "EXIT") {
				break;
			} else {
				std::cout << "Invalid command." << std::endl;
			}
		} else {
			std::cout << std::endl;
			exit(1);
		}
    }

    return 0;
}
