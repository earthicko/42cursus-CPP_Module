#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <string>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
						WrongCat(void);
						WrongCat(const WrongCat &orig);
		virtual			~WrongCat(void);
		WrongCat		&operator=(const WrongCat &orig);

		virtual void	makeSound(void) const;
};

#endif
