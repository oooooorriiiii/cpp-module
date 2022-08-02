//
// Created by yuumo on 2022/08/02.
//

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "default constructor is called in FragTrap" << std::endl;
};

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "Constructor is called in FragTrap" << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor is called in FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragTrap) {
	std::cout << "Copy constructor is called in FragTrap" << std::endl;
	*this = fragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap &fragTrap) {
	_name = fragTrap._name;
	_hitPoints = fragTrap._hitPoints;
	_energyPoints = fragTrap._energyPoints;
	_attackDamage = fragTrap._attackDamage;
	return *this;
}

void FragTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << _name << " can't attack " << target << " any more." << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "High fives please!" << std::endl;
}