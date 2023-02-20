#ifndef FORM_HPP
# define FORM_HPP

# include <ostream>
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	AForm
{
	public:
							AForm(const AForm &orig);
		virtual				~AForm(void);
		AForm				&operator=(const AForm &orig);

							AForm
							(
								const std::string &name,
								const std::string &formType,
								int reqGradeToSign,
								int reqGradeToExec
							);

		const std::string	&getName(void) const;
		const std::string	&getFormType(void) const;
		bool				isSigned(void) const;
		int					getReqGradeToSign(void) const;
		int					getReqGradeToExec(void) const;
		void				beSigned(const Bureaucrat &signer);
		virtual void		execute(const Bureaucrat &executor) const = 0;

	private:
							AForm(void);

		const std::string	_formType;
		const std::string	_name;
		bool				_isSigned;
		const int			_reqGradeToSign;
		const int			_reqGradeToExec;

	public:
		class				GradeTooHighException;
		class				GradeTooLowException;
};

std::ostream	&operator<<(std::ostream &os, const AForm& form);

class	AForm::GradeTooHighException: public std::runtime_error
{
	public:
		GradeTooHighException(int grade);
};

class	AForm::GradeTooLowException: public std::runtime_error
{
	public:
		GradeTooLowException(int grade);
};

#endif
