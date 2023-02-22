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
		virtual						~AForm(void);
		AForm						&operator=(const AForm &orig);

									AForm
									(
										const std::string &name,
										int reqGradeToSign,
										int reqGradeToExec
									);

		const std::string			&getName(void) const;
		bool						isSigned(void) const;
		int							getReqGradeToSign(void) const;
		int							getReqGradeToExec(void) const;
		void						beSigned(const Bureaucrat &signer);
		void						checkExecGrade(const Bureaucrat &executor) const;
		virtual void				execute(const Bureaucrat &executor) const = 0;

	protected:
		void						setSigned(bool isSigned);

	private:
									AForm(void);

		const static std::string	_defaultName;
		const std::string			_name;
		const std::string			_formType;
		bool						_isSigned;
		const int					_reqGradeToSign;
		const int					_reqGradeToExec;

	public:
		class						GradeTooHighException;
		class						GradeTooLowException;
		class						FormNotSignedException;
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

class	AForm::FormNotSignedException: public std::runtime_error
{
	public:
		FormNotSignedException(void);
};

#endif
