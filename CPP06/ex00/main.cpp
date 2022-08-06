//
// Created by yuumo on 2022/08/02.
//

#include <iostream>

#include "ScalarConversion.hpp"

int	main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cerr << "Argument error" << std::endl;
		return -1;
	}
//	const std::string argString(argv[1]);
	ScalarConversion argument(argv[1]);
	argument.printAll();
	return 0;
}