//
// Created by yuumo on 2022/08/06.
//

#ifndef EX00_SCALARCONVERSION_HPP
#define EX00_SCALARCONVERSION_HPP

#include <iostream>
#include <cerrno>
#include <cstdlib>
#include <climits>

class ScalarConversion {
public:
	ScalarConversion();
	ScalarConversion(const std::string &arg);
	ScalarConversion(const ScalarConversion& sc);
	ScalarConversion& operator=(const ScalarConversion& sc);
	~ScalarConversion();


	/*
	 * Member functions
	 */

	void	printAll() const ;
//	void	convert() const ;

private:
	std::string _argumentString;
	char 		_char;
	int 		_int;
	float 		_float;
	double		_double;
	std::string _message_char;
	std::string _message_int;
	std::string _message_float;
	std::string _message_double;

	static const std::string _kDefaultMessage;

	void	_convertChar();
	void	_convertInt();
//	void	_convertFloat();
//	void	_convertDouble();

	void	_printChar() const;
	void	_printInt() const;

	static int 	_ftStoI(const std::string &str, std::size_t *idx = NULL, int base = 10);
};


#endif //EX00_SCALARCONVERSION_HPP
