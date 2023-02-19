#ifndef FORM_HPP
# define FORM_HPP

# include <ostream>
# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
							Form(const Form &orig);
							~Form(void);
		Form				&operator=(const Form &orig);

							Form
							(
								const std::string &name,
								int reqGradeToSign,
								int reqGradeToExec
							);

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		int					getReqGradeToSign(void) const;
		int					getReqGradeToExec(void) const;
		void				beSigned(const Bureaucrat &signer);

	private:
							Form(void);

		const std::string	_name;
		bool				_isSigned;
		const int			_reqGradeToSign;
		const int			_reqGradeToExec;

	public:
		class				GradeTooHighException;
		class				GradeTooLowException;
};

std::ostream	&operator<<(std::ostream &os, const Form& form);

class	Form::GradeTooHighException: public std::runtime_error
{
	public:
		GradeTooHighException(int grade);
};

class	Form::GradeTooLowException: public std::runtime_error
{
	public:
		GradeTooLowException(int grade);
};

#endif
