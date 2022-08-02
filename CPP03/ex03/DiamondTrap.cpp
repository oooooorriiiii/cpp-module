//
// Created by yuumo on 2022/08/02.
//

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap(), _name() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "Default constructor is called in DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "constructor is called in DiamondTrap" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "destructor is called in DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) {
	std::cout << "copy constructor in DiamondTrap" << std::endl;
	*this = diamondTrap;
}

void DiamondTrap::attack(const std::string &target) {
	this->ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "         Name is " << _name << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
	(std::string)_name = diamondTrap._name;
	_hitPoints = diamondTrap._hitPoints;
	_energyPoints = diamondTrap._energyPoints;
	_attackDamage = diamondTrap._attackDamage;
	return *this;
}