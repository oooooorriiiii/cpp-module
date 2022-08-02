//
// Created by yuumo on 2022/08/02.
//

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main() {
	ScavTrap BobBot("BobBot");

	BobBot.attack("Alice");
	BobBot.takeDamage(5);
	BobBot.beRepaired(5);
	BobBot.takeDamage(100);

	BobBot.guardGate();

	return 0;
}