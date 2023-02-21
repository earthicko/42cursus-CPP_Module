#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"

const std::string	RobotomyRequestForm::_defaultName = "RobotomyRequestForm";

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm(
		RobotomyRequestForm::_defaultName,
		RobotomyRequestForm::_defaultReqGradeToSign,
		RobotomyRequestForm::_defaultReqGradeToExec)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &orig):
	AForm(orig.getName(), orig.getReqGradeToSign(), orig.getReqGradeToExec())
{
	setSigned(orig.isSigned());
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &orig)
{
	if (this == &orig)
		return (*this);
	std::cerr << "Warning: Form name, type and required grades will not be initialized using operator=\n";
	setSigned(orig.isSigned());
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm(
		RobotomyRequestForm::_defaultName,
		RobotomyRequestForm::_defaultReqGradeToSign,
		RobotomyRequestForm::_defaultReqGradeToExec),
	_target(target)
{
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
		throw (AForm::FormNotSignedException());
	checkExecGrade(executor);
	std::cout << getName() << ": making some drilling noises\n";
	if (rand() % 2)
		std::cout << getName() << ": " << _target << " has been robotomised sucessfully.\n";
	else
		std::cout << getName() << ": " << _target << " has not been robotomised sucessfully.\n";
}
