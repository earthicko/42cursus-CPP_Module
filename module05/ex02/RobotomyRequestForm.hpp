#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
	public:
									RobotomyRequestForm(void);
									RobotomyRequestForm(const RobotomyRequestForm &orig);
									~RobotomyRequestForm(void);
		RobotomyRequestForm			&operator=(const RobotomyRequestForm &orig);

		virtual void				execute(const Bureaucrat &executor) const;

	private:
		const static std::string	_defaultFormType;
		const static int			_defaultReqGradeToSign = 72;
		const static int			_defaultReqGradeToExec = 45;
};

#endif
