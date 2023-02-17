#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	public:
									Character(void);
									Character(const Character &orig);
									~Character(void);
		Character					&operator=(const Character &orig);

									Character(const std::string &name);

		virtual std::string const	&getName(void) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);

	private:
		const static int			_nSlots = 4;
		AMateria					*_slot[_nSlots];
		std::string					_name;
};

#endif
