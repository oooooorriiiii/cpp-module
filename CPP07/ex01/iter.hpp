//
// Created by yuumo on 2022/08/10.
//

#ifndef EX01_ITER_HPP
#define EX01_ITER_HPP

#include <iostream>

template<typename T>
void iter(T* arr, std::size_t arrLen, void (func)(T&)) {
	for (std::size_t i = 0; i < arrLen; i++)
		func(arr[i]);
}

#endif //EX01_ITER_HPP
