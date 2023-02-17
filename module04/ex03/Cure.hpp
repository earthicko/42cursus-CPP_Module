#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure: public AMateria
{
	public:
									Cure(void);
									Cure(const Cure &orig);
		virtual						~Cure(void);
		Cure						&operator=(const Cure &orig);

		virtual AMateria			*clone(void) const;
		virtual void				use(ICharacter &target);
	
	private:
		const static std::string	_typename;
};

#endif
