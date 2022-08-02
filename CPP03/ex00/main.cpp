//
// Created by yuumo on 2022/08/02.
//

#include "ClapTrap.hpp"

int	main() {
	ClapTrap Alice("Alice");
	ClapTrap Bob("Bob");
	ClapTrap Carol("Carol");

	Alice.attack("Bob");
	Alice.takeDamage(5);
	Alice.takeDamage(3);
	Alice.takeDamage(3);
	Alice.beRepaired(3);
	Alice.takeDamage(3);
}