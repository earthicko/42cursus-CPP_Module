#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
	public:
									ShrubberyCreationForm(const ShrubberyCreationForm &orig);
									~ShrubberyCreationForm(void);
		ShrubberyCreationForm		&operator=(const ShrubberyCreationForm &orig);

									ShrubberyCreationForm(const std::string &target);

		virtual void				execute(const Bureaucrat &executor) const;

	private:
									ShrubberyCreationForm(void);

		const static std::string	_defaultName;
		const static int			_defaultReqGradeToSign = 145;
		const static int			_defaultReqGradeToExec = 137;
		const std::string			_target;
};

#endif
