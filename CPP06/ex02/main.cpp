//
// Created by yuumo on 2022/08/02.
//

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/**
 * It randomly instantiates.
 * @return the instance as a Base pointer
 */
Base*   generate(void) {
	std::srand(time(NULL));
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "A is generated" << std::endl;
			return new A();
		case 1:
			std::cout << "B is generated" << std::endl;
			return new B();
		default:
			std::cout << "C is generated" << std::endl;
			return new C();
	}
}

/**
 * This function prints the actual type of the object pointed to by p.
 */
void identify(Base* p) {

	if (dynamic_cast<A *>(p))
		std::cout << "pointer type is A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "pointer type is B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "pointer type is C" << std::endl;
	else
		std::cout << "pointer type is unknown" << std::endl;
}

/**
 * This function prints the actual type of the object pointed to by p.
 */
void    identify(Base& p) {

	try
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "pointer type is A" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "pointer type is B" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "pointer type is C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
}


int	main() {
	std::cout << "[ Base * generate(void) ]" << std::endl;
	Base *p = generate();

	std::cout << "[ void identify(Base* p) ]" << std::endl;
	identify(p);

	std::cout << "[ void identify(Base& p) ]" << std::endl;
	Base &ref = *p;
	identify(ref);

	delete p;
	return 0;
}