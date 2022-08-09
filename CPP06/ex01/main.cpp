//
// Created by yuumo on 2022/08/02.
//

#include <iostream>

#include <stdint.h>

struct Data{
	std::string _data01;
	std::string _data02;
};

uintptr_t   serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*   deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int	main() {
	Data    test;
	test._data01 = "42";
	test._data02 = "student";

	std::cout << &test << std::endl;
	std::cout << deserialize(serialize(&test)) << std::endl;
	return 0;
}