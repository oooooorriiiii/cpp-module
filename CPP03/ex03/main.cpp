//
// Created by yuumo on 2022/08/02.
//

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main() {
	FragTrap Carol("Carol");

	Carol.attack("Alice");
	Carol.takeDamage(5);
	Carol.beRepaired(5);
	Carol.takeDamage(100);

	Carol.highFivesGuys();

	return 0;
}