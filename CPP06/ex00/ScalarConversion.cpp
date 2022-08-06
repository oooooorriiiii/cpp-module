//
// Created by yuumo on 2022/08/06.
//

#include "ScalarConversion.hpp"

const std::string ScalarConversion::_kDefaultMessage = "nop";

ScalarConversion::ScalarConversion() {}

ScalarConversion::ScalarConversion(const std::string &arg) : _argumentString(arg),
								_char(0), _int(0), _float(0), _double(0),
													_message_char(_kDefaultMessage),
													 _message_int(_kDefaultMessage),
													 _message_float(_kDefaultMessage),
													 _message_double(_kDefaultMessage) {
	_convertChar();
	(void)_double;
	(void)_int;
	(void)_float;
}

ScalarConversion::ScalarConversion(const ScalarConversion &sc) {
	*this = sc;
}

ScalarConversion& ScalarConversion::operator=(const ScalarConversion &sc) {
	if (this == &sc)
		return *this;
	_argumentString = sc._argumentString;
	return *this;
}

ScalarConversion::~ScalarConversion() {}


/*
 * Member functions
 */

void	ScalarConversion::printAll() const {
	_printChar();
}

/*
 * Private function
 */

void	ScalarConversion::_convertChar() {

	try
	{
		if (_argumentString.length() == 1 && !std::isdigit(_argumentString[0]))
		{
			_char = static_cast<char>(_argumentString[0]);
		}
		else if (_ftStoI(_argumentString) >= 0 && _ftStoI(_argumentString) <= 127)
		{
			_char = static_cast<char>(_ftStoI(_argumentString));
		}

		if (!std::isprint(_char))
			_message_char = "Non displayable";
	}
	catch (...)
	{
		_message_char = "impossible";
	}
}

void	ScalarConversion::_printChar() const {
	std::cout << "char: ";
	if (_message_char == _kDefaultMessage)
		std::cout << "\'" << _char  << "\'" << std::endl;
	else
		std::cout << _message_char << std::endl;
}

int ScalarConversion::_ftStoI(const std::string &str, std::size_t *idx,
							  int base) {
	const char *p = str.c_str();
	char *end;
	errno = 0;
	long x = std::strtol(p, &end, base); // C++98
	if (p == end) {
		throw std::invalid_argument("ftStoI");
	}
	if (errno == ERANGE || x < INT_MIN || INT_MAX < x) {
		throw std::out_of_range("ftStoI");
	}
	if (idx != NULL) {
		*idx = static_cast<std::size_t>(end - p);
	}
	return static_cast<int>(x);
}
