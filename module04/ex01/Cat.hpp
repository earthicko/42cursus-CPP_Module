#ifndef CAT_HPP
# define CAT_HPP

# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
	public:
									Cat(void);
									Cat(const Cat &orig);
		virtual						~Cat(void);
		Cat							&operator=(const Cat &orig);

		virtual void				makeSound(void) const;
		void						setIdea(const std::string &idea, int i);
		const std::string			&getIdea(int i) const;

	private:
		const static std::string	_defaultType;
		Brain						*brain;
};

#endif
