//
// Created by yuumo on 2022/08/02.
//

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default constructor is called in Cat" << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type) {
	std::cout << "Constructor is called in Cat" << std::endl;
}

Cat::Cat(const Cat &cat) {
	*this = cat;
	std::cout << "Copy constructor is called in Cat" << std::endl;
}

Cat::~Cat() {
	std::cout << "destructor is called in Cat" << std::endl;
}

Cat& Cat::operator=(const Cat &cat) {
	std::cout << "Assignation operator is called in Cat" << std::endl;
	_type = cat._type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "NYAN" << std::endl;
}
