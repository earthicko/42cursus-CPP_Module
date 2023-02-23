#ifndef DOG_HPP
# define DOG_HPP

# include <string>
# include "Animal.hpp"

class Dog: public Animal
{
	public:
									Dog(void);
									Dog(const Dog &orig);
		virtual						~Dog(void);
		Dog							&operator=(const Dog &orig);

		virtual void				makeSound(void) const;

	private:
		const static std::string	_defaultType;
};

#endif
