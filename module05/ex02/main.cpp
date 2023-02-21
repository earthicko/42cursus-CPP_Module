#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	testPresidentialPardonForm(void)
{
	Bureaucrat				choi("choi", 26);
	Bureaucrat				lee("lee", 24);
	Bureaucrat				kim("kim", 4);
	PresidentialPardonForm	form("donghyle");
	PresidentialPardonForm	form2(form);

	kim.executeForm(form);
	lee.signForm(form);
	lee.executeForm(form);
	kim.executeForm(form);
	choi.signForm(form);
	choi.executeForm(form);
	choi.signForm(form2);
	lee.signForm(form2);
	kim.executeForm(form2);
}

void	testRobotomyRequestForm(void)
{
	Bureaucrat			choi("choi", 73);
	Bureaucrat			lee("lee", 72);
	Bureaucrat			kim("kim", 45);
	RobotomyRequestForm	form("donghyle");

	kim.executeForm(form);
	lee.signForm(form);
	lee.executeForm(form);
	for (int i = 0; i < 5; i++)
		kim.executeForm(form);
	choi.signForm(form);
	choi.executeForm(form);
}

void	testShrubberyCreationForm(void)
{
	Bureaucrat				choi("choi", 146);
	Bureaucrat				lee("lee", 145);
	Bureaucrat				kim("kim", 137);
	ShrubberyCreationForm	form("donghyle");

	kim.executeForm(form);
	lee.signForm(form);
	lee.executeForm(form);
	for (int i = 0; i < 5; i++)
		kim.executeForm(form);
	choi.signForm(form);
	choi.executeForm(form);
}

int	main(void)
{
	testPresidentialPardonForm();
	testRobotomyRequestForm();
	testShrubberyCreationForm();
	return (0);
}
