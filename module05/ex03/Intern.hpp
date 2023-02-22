#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class	Intern
{
	public:
									Intern(void);
									Intern(const Intern &orig);
									~Intern(void);
		Intern						&operator=(const Intern &orig);

		AForm						*makeForm(const std::string &name, const std::string &target);

	private:
		const static int			_nFormTypes = 3;
		const static std::string	_formnames[_nFormTypes];
		static AForm				*(*_formFactories[_nFormTypes])(const std::string &);

	public:
		class						FormNameNotFoundException;
};

class	Intern::FormNameNotFoundException: public std::runtime_error
{
	public:
		FormNameNotFoundException(const std::string &name);
};

AForm	*newPresidentialPardonForm(const std::string &target);
AForm	*newRobotomyRequestForm(const std::string &target);
AForm	*newShrubberyCreationForm(const std::string &target);

#endif
