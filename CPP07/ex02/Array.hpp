//
// Created by yuumo on 2022/08/10.
//

#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP

#include <iostream>

template<typename T>
class Array{
public:
	Array();
	Array(unsigned int n);
	Array(const Array& array);
	Array& operator=(const Array& array);
	~Array();

	T&  operator[](const size_t index) const throw(std::exception);
private:
	T*              _arr;
	unsigned int    _n;
};

#endif //EX02_ARRAY_HPP
