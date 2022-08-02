//
// Created by yuumo on 2022/08/02.
//

#ifndef EX03_DIAMONDTRAP_HPP
#define EX03_DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& diamondTrap);
	DiamondTrap& operator=(const DiamondTrap& diamondTrap);

	void attack(const std::string& target);
	void whoAmI();

private:
	const std::string _name;
};


#endif //EX03_DIAMONDTRAP_HPP
