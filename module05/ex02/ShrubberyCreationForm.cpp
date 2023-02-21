#include <iostream>
#include <fstream>
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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm(
		ShrubberyCreationForm::_defaultName,
		ShrubberyCreationForm::_defaultReqGradeToSign,
		ShrubberyCreationForm::_defaultReqGradeToExec),
	_target(target)
{
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	file;

	if (!isSigned())
		throw (AForm::FormNotSignedException());
	checkExecGrade(executor);
	file.open(_target + "_shrubbery", std::ios::out | std::ios::trunc);
	if (file.is_open())
	{
		file << "       v\n"
			<< "      >X<\n"
			<< "       A\n"
			<< "      d$b\n"
			<< "    .d$$$b.\n"
			<< "  .d$i$$$$$b.\n"
			<< "     d$$$@b\n"
			<< "    d$$$$ib\n"
			<< "  .d$$$$$$$b\n"
			<< "      ###\n";
		file.close();
	}
	else
		std::cerr << "I/O Error: Unable to open file." << std::endl;
}
