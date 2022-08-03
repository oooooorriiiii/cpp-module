//
// Created by yuumo on 2022/08/02.
//

#ifndef EX03_AMATERIA_HPP
#define EX03_AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria {
protected:
	std::string	_type;
	AMateria(std::string const & type);

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& copy);
	AMateria& operator=(const AMateria& aMateria);
	virtual ~AMateria();

	std::string const & getType() const;

	virtual AMateria* close() const = 0;
	virtual void use(ICharacter& target);
};


#endif //EX03_AMATERIA_HPP
