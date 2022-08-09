//
// Created by yuumo on 2022/08/02.
//

#include "iter.hpp"

template <typename T>
void    printElems(T& elem) {
	std::cout << elem << std::endl;
}

template <typename T>
void    incrementElems(T& elem) {
	elem++;
}

int	main() {
	int arr[3] = {1, 2, 3};
	iter(arr, 3, printElems);
	iter(arr, 3, incrementElems);
	iter(arr, 3, printElems);

	std::cout << "**********" << std::endl;

	const int arr1[3] = {1, 2, 3};
	iter(arr1, 3, printElems);

	std::cout << "**********" << std::endl;

	double arr2[3] = {1.0, 2.0, 3.0};
	iter(arr2, 3, printElems);
	iter(arr2, 3, incrementElems);
	iter(arr2, 3, printElems);

	return 0;
}