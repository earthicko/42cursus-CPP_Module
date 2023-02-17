#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice: public AMateria
{
	public:
									Ice(void);
									Ice(const Ice &orig);
		virtual						~Ice(void);
		Ice							&operator=(const Ice &orig);

		virtual AMateria			*clone(void) const;
		virtual void				use(ICharacter &target);
	
	private:
		const static std::string	_typename;
};

#endif
