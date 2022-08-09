//
// Created by yuumo on 2022/08/06.
//

#include "ScalarConversion.hpp"

const std::string ScalarConversion::_kDefaultMessage = "nop";

ScalarConversion::ScalarConversion() {}

ScalarConversion::ScalarConversion(const std::string &arg) : _argumentString(
		arg),
															 _char(0),
															 _int(0),
															 _float(0),
															 _double(0),
															 _message_char(
																	 _kDefaultMessage),
															 _message_int(
																	 _kDefaultMessage),
															 _message_float(
																	 _kDefaultMessage),
															 _message_double(
																	 _kDefaultMessage) {
	_convertChar();
	_convertInt();
	_convertFloat();
	_convertDouble();
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
//	std::cout << _argumentString << "  length: " << _argumentString.length() << std::endl;
	_printChar();
	_printInt();
	_printFloat();
	_printDouble();
}


/*
 * Private function
 */

/**
 * ex)
 * input: 0
 * _message_char = "Not displayable"
 *
 * input: 42
 * _char = '*'
 *
 * input: a
 * _char = 'a'
 *
 * input: 1.26e+02
 * _char = '~'
 *
 * input: 128 ~ 255
 * _message_char = "Not exist in ASCII code"
 *
 * input: 256 ~
 * _message_char = "impossible"
 *
 * input :INT_MAX
 * _message_char = "impossible"
 *
 * input: INT_MAX + 1
 * _message_char = "impossible"
 * Because _ftStoI() throws std::out_of_range and this function catches it.
 *
 * input: nan
 * _message_char = "impossible"
 * Because _ftStoI() throws std::invalid_argument and this function catches it.
 *
 */
void	ScalarConversion::_convertChar() {
	try
	{
		if (_argumentString.length() == 1 && !std::isdigit(_argumentString[0]))
			_char = static_cast<char>(_argumentString[0]);
		else if (_ftStoD(_argumentString) >= 0 && _ftStoD(_argumentString) <= 255)
		{
			_char = static_cast<char>(_ftStoD(_argumentString));
			if (_char >= 0 &&  _char <= 127)
			{
				if (!std::isprint(_char))
					_message_char = "Non displayable";
			} else {
				_message_char = "Not exist in ASCII code";
			}
		}
		else
			_message_char = "impossible";
	}
	catch (...)
	{
		_message_char = "impossible";
	}
}

void	ScalarConversion::_convertInt() {
	try
	{
		if (_argumentString.length() == 1 && !std::isdigit(_argumentString[0]) && std::isprint(_argumentString[0]))
			_int = static_cast<int>(_argumentString[0]);
		else if (_ftStoD(_argumentString) < INT_MIN  || INT_MAX < _ftStoD(_argumentString))
			_message_int = "impossible";
		else {
			if (INT_MIN < _ftStoD(_argumentString) && _ftStoD(_argumentString) < INT_MAX)
				// Cast return value of stod() because stoi() does not support exponential notation.
				_int = static_cast<int>(_ftStoD(_argumentString));
			else
				// use stoi because handle 'nan'
				_int = static_cast<int>(_ftStoI(_argumentString));
		}
	}
	catch (...)
	{
		_message_int = "impossible";
	}
}

void	ScalarConversion::_convertFloat() {
	try
	{
		if (_argumentString.length() == 1 && !std::isdigit(_argumentString[0]) && std::isprint(_argumentString[0]))
			_float = static_cast<float>(_argumentString[0]);
		else
			_float = static_cast<float>(_ftStoF(_argumentString));
	}
	catch (...)
	{
		_message_float = "impossible";
	}
}

void	ScalarConversion::_convertDouble() {
	try
	{
		if (_argumentString.length() == 1 && !std::isdigit(_argumentString[0]) && std::isprint(_argumentString[0]))
			_double = static_cast<double>(_argumentString[0]);
		else
			_double = static_cast<double>(_ftStoD(_argumentString));
	}
	catch (...)
	{
		_message_double = "impossible";
	}
}

void	ScalarConversion::_printChar() const {
//	std::cout << "messege: " << _message_char << std::endl; // D
	std::cout << "char: ";
	if (_message_char == _kDefaultMessage)
		std::cout << "\'" << _char  << "\'" << std::endl;
	else
		std::cout << _message_char << std::endl;
}

void	ScalarConversion::_printInt() const {
	std::cout << "int: ";
	if (_message_int == _kDefaultMessage)
		std::cout << _int << std::endl;
	else
		std::cout << _message_int << std::endl;
}

/**
 * ex)
 * input: 999999
 * 999999.0f
 *
 * input: 1000000
 * 1e+06f
 *
 * input: 2147483647 (INT_MAX)
 * 2.14748e+09f
 *
 * input: 2147483648 (INT_MAX + 1)
 * 2.14748e+09f
 *
 * input: (Number beyond the range of float type)
 * impossible
 *
 */
void	ScalarConversion::_printFloat() const {
	std::cout << "float: ";
	if (_message_float == _kDefaultMessage)
	{
		std::cout << _float;
		// If decimals did not exist and less than 10 to the sixth power, add ".0"
		if (static_cast<int>(_float) - _float == 0.f && _float < 1000000.f)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	else
	{
		std::cout << _message_float << std::endl;
	}
}

/**
 * ex)
 * input: 999999
 * 999999.0
 *
 * input: 1000000
 * 1e+06
 *
 * input: 2147483647 (INT_MAX)
 * 2.14748e+09
 *
 * input: 2147483648 (INT_MAX + 1)
 * 2.14748e+09
 *
 * input: (Number beyond the range of double type)
 * impossible
 *
 */
void	ScalarConversion::_printDouble() const {
	std::cout << "double: ";
	if (_message_double == _kDefaultMessage)
	{
		std::cout << _double;
		// If decimals did not exist and less than 10 to the sixth power, add ".0"
		if (static_cast<int>(_double) - _double == 0. && _double < 1000000.)
			std::cout << ".0";
		std::cout << std::endl;
	}
	else
	{
		std::cout << _message_double << std::endl;
	}
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
	if (idx != NULL) { // nullptr is C++11 !!
		*idx = static_cast<std::size_t>(end - p);
	}
	return static_cast<int>(x);
}


// Debug for using _ftStoF
// double x = strtof(p, &end); // std::strtof is not C++98 !!

float ScalarConversion::_ftStoF(const std::string &str, std::size_t *idx) {
	const char *p = str.c_str();
	char *end;
	errno = 0;
	double x = _ftStrToF(p, &end); // std::strtof is not C++98 !!
	if (p == end) {
		throw std::invalid_argument("ftStoF");
	}
	if (errno == ERANGE) {
		throw std::out_of_range("ftStoF");
	}
	if (idx != NULL) {
		*idx = static_cast<std::size_t>(end - p);
	}
	return static_cast<float>(x);
}

double ScalarConversion::_ftStoD(const std::string &str, std::size_t *idx) {
	const char *p = str.c_str();
	char *end;
	errno = 0;
	double x = std::strtod(p, &end); // C++98
	if (p == end) {
		throw std::invalid_argument("ftStoD");
	}
	if (errno == ERANGE) {
		throw std::out_of_range("ftStoD");
	}
	if (idx != NULL) {
		*idx = static_cast<std::size_t>(end - p);
	}
	return x;
}

float ScalarConversion::_ftStrToF(const char *nptr, char **endptr) {
	int caller_errno = errno;
	double dresult;
	float fresult;

	errno = 0;
	dresult = std::strtod(nptr, endptr);
	fresult = static_cast<float>(dresult);

	if (errno == 0) {
		if (dresult != 0 && fresult == 0)
			caller_errno = ERANGE;
		if (!_ftIsInf(dresult) && _ftIsInf(fresult))
			caller_errno = ERANGE;
	}
	else
		caller_errno = errno;

	errno = caller_errno;
	return fresult;
}

/**
 * reference: IEEE754-1985
 * @param x
 * @return
 */
int ScalarConversion::_ftIsInf(double x) {
	union { unsigned long u; double f; } elem = {}; // u_int64_t is C++11 !!
	elem.f = x;
	return	( (unsigned)(elem.u >> 32) & 0x7fffffff) == 0x7ff00000 &&
			  ( (unsigned)elem.u == 0 );
}
