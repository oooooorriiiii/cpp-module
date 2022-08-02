//
// Created by yuumo on 2022/08/02.
//

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << "***************************" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongCat*    k = new WrongCat();
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete k;

	return 0;
}