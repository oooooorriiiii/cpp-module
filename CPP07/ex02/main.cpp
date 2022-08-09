//
// Created by yuumo on 2022/08/10.
//

#include "Array.hpp"
#include "Array.tpp"

int main() {

	Array<int> arrInt(5);
	try
	{
		for (int i = 0; i < 5; i++)
			arrInt[i] = i;
		for (int i = 0; i < 5; i++)
			std::cout << arrInt[i] << std::endl;
	}
	catch (...)
	{

	}

	return 0;
}