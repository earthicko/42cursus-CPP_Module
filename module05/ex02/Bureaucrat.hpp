#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define GRADE_MIN 1
# define GRADE_MAX 150

# include <ostream>
# include <string>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	public:
							Bureaucrat(const Bureaucrat &orig);
							~Bureaucrat(void);
		Bureaucrat			&operator=(const Bureaucrat &orig);

							Bureaucrat(const std::string &name, int grade);

		const std::string	&getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				signForm(AForm &form);
		void				executeForm(const AForm &form);

	private:
							Bureaucrat(void);

		void				setGrade(int grade);

		const std::string	_name;
		int					_grade;

	public:
		class				GradeTooHighException;
		class				GradeTooLowException;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat& bureaucrat);

class	Bureaucrat::GradeTooHighException: public std::runtime_error
{
	public:
		GradeTooHighException(int grade);
};

class	Bureaucrat::GradeTooLowException: public std::runtime_error
{
	public:
		GradeTooLowException(int grade);
};

#endif
