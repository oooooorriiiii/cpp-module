#include <cstdlib>
#include "Phonebook.hpp"

int main() {
    std::string cmd;
    Phonebook   phonebook;

    while (true) {
        std::cout << "Please your command [EXIT, ADD, SEARCH]" << std::endl << ">";

		if (!std::getline(std::cin, cmd, '\n')) {
			std::cout << std::endl;
			exit(1);
		}

        if (cmd == "ADD"){
			phonebook.addContact();
        } else if (cmd == "SEARCH") {
			phonebook.showContactTable();
			phonebook.search();
        } else if (cmd == "EXIT") {
            break;
        } else if (cmd.empty()) { // enter only. After reading a command.
			continue;
		} else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}