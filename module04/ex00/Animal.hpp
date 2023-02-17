#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	public:
							Animal(void);
							Animal(const Animal &orig);
							~Animal(void);
		Animal				&operator=(const Animal &orig);

		virtual void		makeSound(void) const;
		const std::string	&getType(void) const;

	protected:
		std::string			type;
};

#endif
