#include <iostream>
#include <sstream>
#include "Form.hpp"

static std::string	intToString(int val)
{
	std::ostringstream	strm;

	strm << val;
	return strm.str();
}

static void	throwGradeTooHighException(int grade)
{
	if (grade < GRADE_MIN)
		throw (Form::GradeTooHighException(grade));
}

static void	throwGradeTooLowException(int grade)
{
	if (grade > GRADE_MAX)
		throw (Form::GradeTooLowException(grade));
}

Form::Form(const Form &orig):
	_name(orig._name),
	_isSigned(orig._isSigned),
	_reqGradeToSign(orig._reqGradeToSign),
	_reqGradeToExec(orig._reqGradeToExec)
{
}

Form::~Form(void)
{
}

Form	&Form::operator=(const Form &orig)
{
	if (this == &orig)
		return (*this);
	std::cerr << "Warning: Form name and required grades will not be initialized using operator=\n";
	_isSigned = orig._isSigned;
	return (*this);
}

Form::Form(const std::string &name, int reqGradeToSign, int reqGradeToExec):
	_name(name),
	_isSigned(false),
	_reqGradeToSign(reqGradeToSign),
	_reqGradeToExec(reqGradeToExec)
{
	throwGradeTooHighException(_reqGradeToSign);
	throwGradeTooLowException(_reqGradeToSign);
	throwGradeTooHighException(_reqGradeToExec);
	throwGradeTooLowException(_reqGradeToExec);
}

const std::string	&Form::getName(void) const
{
	return (_name);
}

bool	Form::isSigned(void) const
{
	return (_isSigned);
}

int	Form::getReqGradeToSign(void) const
{
	return (_reqGradeToSign);
}

int	Form::getReqGradeToExec(void) const
{
	return (_reqGradeToExec);
}

void	Form::beSigned(const Bureaucrat &signer)
{
	if (_isSigned)
		return ;
	if (signer.getGrade() > _reqGradeToSign)
		throw (GradeTooLowException(signer.getGrade()));
	_isSigned = true;
}

Form::Form(void):
	_name(""),
	_isSigned(false),
	_reqGradeToSign(GRADE_MIN),
	_reqGradeToExec(GRADE_MIN)
{
}

std::ostream	&operator<<(std::ostream &os, const Form& form)
{
	os << "Form " << form.getName() << ": ";
	os << "sign grade " << form.getReqGradeToSign() << ", ";
	os << "exec grade " << form.getReqGradeToExec() << ", ";
	if (form.isSigned())
		os << "signed";
	else
		os << "not signed";
	return (os);
}

Form::GradeTooHighException::GradeTooHighException(int grade):
	std::runtime_error("Grade " + intToString(grade) + " is too high")
{
}

Form::GradeTooLowException::GradeTooLowException(int grade):
	std::runtime_error("Grade " + intToString(grade) + " is too low")
{
}
