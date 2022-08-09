#include "Array.hpp"

template<typename T>
Array<T>::Array() : _arr(NULL), _n(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _n(n) {}

template<typename T>
Array<T>::Array(const Array<T> &array) {
	*this = array;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &array) {
	delete [] _arr;
	_n = array._n;
	_arr = new T[_n];
	for (size_t i = 0; i < _n; i++)
		_arr[i] = array._arr[i];
	return *this;
}

template<typename T>
Array<T>::~Array() {
	delete [] _arr;
}

template<typename T>
T& Array<T>::operator[](const size_t index) const throw(std::exception) {
	if (index < 0 || index >= _n)
		throw std::out_of_range("Index is out of range");
	return _arr[index];
}
