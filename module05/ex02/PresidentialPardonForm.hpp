#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

class	PresidentialPardonForm: public AForm
{
	public:
									PresidentialPardonForm(void);
									PresidentialPardonForm(const PresidentialPardonForm &orig);
									~PresidentialPardonForm(void);
		PresidentialPardonForm		&operator=(const PresidentialPardonForm &orig);

		virtual void				execute(const Bureaucrat &executor) const;

	private:
		const static std::string	_defaultFormType;
		const static int			_defaultReqGradeToSign = 25;
		const static int			_defaultReqGradeToExec = 5;
};

#endif
