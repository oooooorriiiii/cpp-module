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

ScavTrap::ScavTrap(const ScavTrap &form) {
	std::cout << "copy constructor in ScavTrap" << std::endl;
	*this = form;
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
