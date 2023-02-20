#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
	public:
									ShrubberyCreationForm(void);
									ShrubberyCreationForm(const ShrubberyCreationForm &orig);
									~ShrubberyCreationForm(void);
		ShrubberyCreationForm		&operator=(const ShrubberyCreationForm &orig);

		virtual void				execute(const Bureaucrat &executor) const;

	private:
		const static std::string	_defaultFormType;
		const static int			_defaultReqGradeToSign = 145;
		const static int			_defaultReqGradeToExec = 137;
};

#endif
