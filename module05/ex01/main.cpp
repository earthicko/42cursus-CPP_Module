#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testConstructors(void)
{
	try
	{
		std::cout << __func__ << ": test Form	a(\"a\", 3, 6);" << std::endl;
		Form a("a", 3, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << __func__ << ": test Form	a(\"a\", 0, 9);" << std::endl;
		Form a("a", 0, 9);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << __func__ << ": test Form	a(\"a\", 9, 151);" << std::endl;
		Form a("a", 9, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testGetters(void)
{
	try
	{
		std::cout << __func__ << ": test getters" << std::endl;
		Form a("a", 3, 9);
		std::cout << a << std::endl;
		std::cout << "getName(): " << a.getName() << std::endl;
		std::cout << "isSigned(): " << a.isSigned() << std::endl;
		std::cout << "getReqGradeToSign(): " << a.getReqGradeToSign() << std::endl;
		std::cout << "getReqGradeToExec(): " << a.getReqGradeToExec() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	testSign(void)
{
	try
	{
		std::cout << __func__ << ": test signForm (impossible)" << std::endl;
		Form a("a", 3, 9);
		Bureaucrat b("b", 4);
		b.signForm(a);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << __func__ << ": test beSigned (impossible)" << std::endl;
		Form a("a", 3, 9);
		Bureaucrat b("b", 4);
		a.beSigned(b);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << __func__ << ": test signForm (possible)" << std::endl;
		Form a("a", 3, 9);
		Bureaucrat b("b", 1);
		b.signForm(a);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << __func__ << ": test beSigned (possible)" << std::endl;
		Form a("a", 3, 9);
		Bureaucrat b("b", 1);
		a.beSigned(b);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
	testConstructors();
	testGetters();
	testSign();
	return (0);
}
