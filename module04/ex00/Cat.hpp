#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"

class Cat: public Animal
{
	public:
						Cat(void);
						Cat(const Cat &orig);
						~Cat(void);
		Cat				&operator=(const Cat &orig);

		virtual void	makeSound(void) const;
};

#endif
