#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
{
	public:
									Dog(void);
									Dog(const Dog &orig);
		virtual						~Dog(void);
		Dog							&operator=(const Dog &orig);

		virtual void				makeSound(void) const;
		void						setIdea(const std::string &idea, int i);
		const std::string			&getIdea(int i) const;

	private:
		const static std::string	_defaultType;
		Brain						*brain;
};

#endif
