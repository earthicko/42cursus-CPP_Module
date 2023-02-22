#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

const std::string	Intern::_formnames[_nFormTypes] =
{
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};
AForm				*(*Intern::_formFactories[_nFormTypes])(const std::string &) =
{
	newPresidentialPardonForm,
	newRobotomyRequestForm,
	newShrubberyCreationForm
};

Intern::Intern(void)
{
}

Intern::Intern(const Intern &orig)
{
	(void)orig;
}

Intern::~Intern(void)
{
}

Intern	&Intern::operator=(const Intern &orig)
{
	(void)orig;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	for (int i = 0; i < Intern::_nFormTypes; i++)
	{
		if (Intern::_formnames[i] == name)
			return (Intern::_formFactories[i](target));
	}
	throw (FormNameNotFoundException(name));
}

Intern::FormNameNotFoundException::FormNameNotFoundException(const std::string &name):
	std::runtime_error("Form \"" + name + "\" not found")
{
}

AForm	*newPresidentialPardonForm(const std::string &target)
{
	AForm	*form;

	form = new PresidentialPardonForm(target);
	return (form);
}

AForm	*newRobotomyRequestForm(const std::string &target)
{
	AForm	*form;

	form = new RobotomyRequestForm(target);
	return (form);
}

AForm	*newShrubberyCreationForm(const std::string &target)
{
	AForm	*form;

	form = new ShrubberyCreationForm(target);
	return (form);
}
