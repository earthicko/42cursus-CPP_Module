#include <iostream>
#include <sstream>
#include "Bureaucrat.hpp"

static std::string	intToString(int val)
{
	std::ostringstream	strm;

	strm << val;
	return strm.str();
}

static void	throwGradeTooHighException(int grade)
{
	if (grade < GRADE_MIN)
		throw (Bureaucrat::GradeTooHighException(grade));
}

static void	throwGradeTooLowException(int grade)
{
	if (grade > GRADE_MAX)
		throw (Bureaucrat::GradeTooLowException(grade));
}

Bureaucrat::Bureaucrat(void):
	_name(""),
	_grade(GRADE_MAX)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &orig):
	_name(orig._name),
	_grade(orig._grade)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &orig)
{
	if (this == &orig)
		return (*this);
	std::cerr << "Warning: Bureaucrat name will not be initialized using operator=\n";
	_grade = orig._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string &name, int grade):
	_name(name),
	_grade(grade)
{
	throwGradeTooHighException(_grade);
	throwGradeTooLowException(_grade);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	throwGradeTooHighException(grade);
	throwGradeTooLowException(grade);
	_grade = grade;
}

void	Bureaucrat::incrementGrade(void)
{
	setGrade(_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	setGrade(_grade + 1);
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cerr << _name << " couldn’t sign " << form.getName() << " because " << e.what() << ".\n";
		return ;
	}
	std::cout << _name << " signed " << form.getName() << "\n";
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int grade):
	std::runtime_error("Grade " + intToString(grade) + " is too high")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int grade):
	std::runtime_error("Grade " + intToString(grade) + " is too low")
{
}
