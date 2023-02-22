#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	testNonExistent(void)
{
	Intern	lee;

	try
	{
		lee.makeForm("fake", "lee");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testCreation(void)
{
	Bureaucrat	master("master", 1);
	Intern		lee;
	AForm		*form;

	try
	{
		form = lee.makeForm("presidential pardon", "lee");
		master.signForm(*form);
		master.executeForm(*form);
		delete form;
		form = lee.makeForm("robotomy request", "lee");
		master.signForm(*form);
		master.executeForm(*form);
		delete form;
		form = lee.makeForm("shrubbery creation", "lee");
		master.signForm(*form);
		master.executeForm(*form);
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	testNonExistent();
	testCreation();
	return (0);
}
