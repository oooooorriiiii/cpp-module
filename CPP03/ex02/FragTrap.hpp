//
// Created by yuumo on 2022/08/02.
//

#ifndef EX02_FRAGTRAP_HPP
#define EX02_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
public:
	FragTrap();
	~FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& fragTrap);

	void attack(const std::string& target);
	void highFivesGuys();

};


#endif //EX02_FRAGTRAP_HPP
