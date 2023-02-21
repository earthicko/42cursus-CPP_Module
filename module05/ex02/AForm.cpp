#include <iostream>
#include <sstream>
#include "AForm.hpp"

const std::string	AForm::_defaultName = "Form";

static std::string	intToString(int val)
{
	std::ostringstream	strm;

	strm << val;
	return strm.str();
}

static void	throwGradeTooHighException(int grade)
{
	if (grade < GRADE_MIN)
		throw (AForm::GradeTooHighException(grade));
}

static void	throwGradeTooLowException(int grade)
{
	if (grade > GRADE_MAX)
		throw (AForm::GradeTooLowException(grade));
}

AForm::AForm(const AForm &orig):
	_name(orig._name),
	_isSigned(orig._isSigned),
	_reqGradeToSign(orig._reqGradeToSign),
	_reqGradeToExec(orig._reqGradeToExec)
{
}

AForm::~AForm(void)
{
}

AForm	&AForm::operator=(const AForm &orig)
{
	if (this == &orig)
		return (*this);
	std::cerr << "Warning: Form name, type and required grades will not be initialized using operator=\n";
	_isSigned = orig._isSigned;
	return (*this);
}

AForm::AForm(const std::string &name, int reqGradeToSign, int reqGradeToExec):
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

const std::string	&AForm::getName(void) const
{
	return (_name);
}

bool	AForm::isSigned(void) const
{
	return (_isSigned);
}

void	AForm::setSigned(bool isSigned)
{
	_isSigned = isSigned;
}

int	AForm::getReqGradeToSign(void) const
{
	return (_reqGradeToSign);
}

int	AForm::getReqGradeToExec(void) const
{
	return (_reqGradeToExec);
}

void	AForm::beSigned(const Bureaucrat &signer)
{
	if (_isSigned)
		return ;
	if (signer.getGrade() > _reqGradeToSign)
		throw (GradeTooLowException(signer.getGrade()));
	_isSigned = true;
}

AForm::AForm(void):
	_name(AForm::_defaultName),
	_isSigned(false),
	_reqGradeToSign(GRADE_MIN),
	_reqGradeToExec(GRADE_MIN)
{
}

std::ostream	&operator<<(std::ostream &os, const AForm& form)
{
	os << form.getName() << ": ";
	os << "sign grade " << form.getReqGradeToSign() << ", ";
	os << "exec grade " << form.getReqGradeToExec() << ", ";
	if (form.isSigned())
		os << "signed";
	else
		os << "not signed";
	return (os);
}

AForm::GradeTooHighException::GradeTooHighException(int grade):
	std::runtime_error("Grade " + intToString(grade) + " is too high")
{
}

AForm::GradeTooLowException::GradeTooLowException(int grade):
	std::runtime_error("Grade " + intToString(grade) + " is too low")
{
}
