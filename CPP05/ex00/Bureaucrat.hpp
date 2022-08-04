//
// Created by yuumo on 2022/08/03.
//

#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat& bureaucrat);
	Bureaucrat& operator=(const Bureaucrat& bureaucrat);
	virtual ~Bureaucrat();

	const std::string&	getName() const;
	unsigned int		getGrade() const;

	void incrementGrade();
	void decrementGrade();

class GradeTooHighException : public std::exception{
public:
	GradeTooHighException();
	virtual ~GradeTooHighException() throw();
//	const char* what() const noexcept override; C++11
	virtual const char* what() const throw();

private:
	std::string _errorMessage;
};

class GradeTooLowException : public std::exception {
public:
	GradeTooLowException();
	virtual ~GradeTooLowException() throw();
	virtual const char* what() const throw();

private:
	std::string _errorMessage;
};


private:
	const std::string 	_name;
	unsigned int		_grade;
};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& bureaucrat);

#endif //EX00_BUREAUCRAT_HPP
