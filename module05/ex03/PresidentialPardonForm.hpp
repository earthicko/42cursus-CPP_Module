#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

class	PresidentialPardonForm: public AForm
{
	public:
									PresidentialPardonForm(const PresidentialPardonForm &orig);
									~PresidentialPardonForm(void);
		PresidentialPardonForm		&operator=(const PresidentialPardonForm &orig);

									PresidentialPardonForm(const std::string &target);

		virtual void				execute(const Bureaucrat &executor) const;

	private:
									PresidentialPardonForm(void);

		const static std::string	_defaultName;
		const static int			_defaultReqGradeToSign = 25;
		const static int			_defaultReqGradeToExec = 5;
		const std::string			_target;
};

#endif
