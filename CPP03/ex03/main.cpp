//
// Created by yuumo on 2022/08/02.
//

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main() {
	DiamondTrap Dave("Dave");

	Dave.attack("Alice");
	Dave.takeDamage(5);
	Dave.beRepaired(5);
	Dave.takeDamage(100);

	Dave.whoAmI();

	return 0;
}