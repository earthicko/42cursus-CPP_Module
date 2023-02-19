#include <iostream>
#include "Bureaucrat.hpp"

void	testConstructor(void)
{
	try
	{
		std::cout << __func__ << ": test normal grades\n";
		Bureaucrat	a("", GRADE_MIN);
		Bureaucrat	b("", (GRADE_MIN + GRADE_MAX) / 2);
		Bureaucrat	c("", GRADE_MAX);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << __func__ << ": test grade under minimum\n";
		Bureaucrat	a("", GRADE_MIN - 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << __func__ << ": test grade over maximum\n";
		Bureaucrat	a("", GRADE_MAX + 1);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testGetters(void)
{
	try
	{
		std::cout << __func__ << ": test getters\n";
		Bureaucrat	a("a", GRADE_MIN + 2);
		std::cout << a << std::endl;
		std::cout << "getName(): " << a.getName() << std::endl;
		std::cout << "getGrade(): " << a.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testGradeSetters(void)
{
	try
	{
		std::cout << __func__ << ": test incrementer\n";
		Bureaucrat	a("a", GRADE_MIN + 2);
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
		std::cout << a << std::endl;
		a.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << __func__ << ": test decrementer\n";
		Bureaucrat	a("a", GRADE_MAX - 1);
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	testConstructor();
	testGetters();
	testGradeSetters();
	return (0);
}
