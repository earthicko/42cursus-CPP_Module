#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
	public:
		virtual						~AAnimal(void);
		virtual void				makeSound(void) const = 0;
		virtual const std::string	&getType(void) const;

	protected:
		std::string			type;
};

#endif
