#include <iostream>
#include "PresidentialPardonForm.hpp"

const std::string	PresidentialPardonForm::_defaultName = "PresidentialPardonForm";

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm(
		PresidentialPardonForm::_defaultName,
		PresidentialPardonForm::_defaultReqGradeToSign,
		PresidentialPardonForm::_defaultReqGradeToExec)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &orig):
	AForm(orig.getName(), orig.getReqGradeToSign(), orig.getReqGradeToExec())
{
	setSigned(orig.isSigned());
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &orig)
{
	if (this == &orig)
		return (*this);
	std::cerr << "Warning: Form name, type and required grades will not be initialized using operator=\n";
	setSigned(orig.isSigned());
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	(void)executor;
}
