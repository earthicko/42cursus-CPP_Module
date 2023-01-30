#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"
class HumanB
{
	public:
					HumanB(std::string name);
					HumanB(const HumanB &orig);
					~HumanB(void);
		HumanB		&operator=(const HumanB &orig);

		void		attack(void) const;
		void		setWeapon(Weapon &weapon);

	private:
		Weapon		*_weapon;
		std::string	_name;
};

#endif
