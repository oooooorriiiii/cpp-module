//
// Created by yuumo on 2022/08/02.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "default constructor is called" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "destructor is called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "constructo is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) : _name(clapTrap._name), _hitPoints(clapTrap._hitPoints), _energyPoints(clapTrap._energyPoints), _attackDamage(clapTrap._attackDamage){
	std::cout << "copy constructor is called" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap &clapTrap) {
	_name = clapTrap._name;
	_hitPoints = clapTrap._hitPoints;
	_energyPoints = clapTrap._energyPoints;
	_attackDamage = clapTrap._attackDamage;
	return *this;
}

void	ClapTrap::attack(const std::string &target) {
	if (_energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	} else {
		std::cout << _name << " can't attack " << target << " any more." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << _name << " took " << amount << " damage!" << std::endl;
	if (amount >= _hitPoints) {
		std::cout << _name << " got hit!!" << std::endl;
		_hitPoints = 0;
	} else {
		_hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	std::cout << _name << " is repaired " << amount << " points." << std::endl;
	_energyPoints += amount;
}

std::string		ClapTrap::getName() const { return _name; }
unsigned int	ClapTrap::getHitPoints() const { return _hitPoints; }
unsigned int	ClapTrap::getEnergyPoints() const { return _energyPoints; }
unsigned int	ClapTrap::getAttackDamage() const { return _attackDamage; }
