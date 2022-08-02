//
// Created by yuumo on 2022/08/02.
//

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "default constructor is called in ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "constructor is called in ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "destructor is called in ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) {
	std::cout << "copy constructor in ScavTrap" << std::endl;
	*this = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &scavTrap) {
	_name = scavTrap._name;
	_hitPoints = scavTrap._hitPoints;
	_energyPoints = scavTrap._energyPoints;
	_attackDamage = scavTrap._attackDamage;
	return *this;
}

void ScavTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << _name << " can't attack " << target << " any more." << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "Gate keeper mode" << std::endl;
}
