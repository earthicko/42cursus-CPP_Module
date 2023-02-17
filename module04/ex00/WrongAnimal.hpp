#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
	public:
							WrongAnimal(void);
							WrongAnimal(const WrongAnimal &orig);
		virtual				~WrongAnimal(void);
		WrongAnimal			&operator=(const WrongAnimal &orig);

		void				makeSound(void) const;
		const std::string	&getType(void) const;

	protected:
		std::string			type;
};

#endif
