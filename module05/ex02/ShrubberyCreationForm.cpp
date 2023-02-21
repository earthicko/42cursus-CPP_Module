#include <iostream>
#include "ShrubberyCreationForm.hpp"

const std::string	ShrubberyCreationForm::_defaultName = "ShrubberyCreationForm";

ShrubberyCreationForm::ShrubberyCreationForm(void):
	AForm(
		ShrubberyCreationForm::_defaultName,
		ShrubberyCreationForm::_defaultReqGradeToSign,
		ShrubberyCreationForm::_defaultReqGradeToExec)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &orig):
	AForm(orig.getName(), orig.getReqGradeToSign(), orig.getReqGradeToExec())
{
	setSigned(orig.isSigned());
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &orig)
{
	if (this == &orig)
		return (*this);
	std::cerr << "Warning: Form name, type and required grades will not be initialized using operator=\n";
	setSigned(orig.isSigned());
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	(void)executor;
}
