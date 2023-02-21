#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
	public:
									RobotomyRequestForm(const RobotomyRequestForm &orig);
									~RobotomyRequestForm(void);
		RobotomyRequestForm			&operator=(const RobotomyRequestForm &orig);

		virtual void				execute(const Bureaucrat &executor) const;

	private:
									RobotomyRequestForm(void);

		const static std::string	_defaultName;
		const static int			_defaultReqGradeToSign = 72;
		const static int			_defaultReqGradeToExec = 45;
};

#endif
