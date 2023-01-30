#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
					HumanA(std::string name, Weapon &weapon);
					HumanA(const HumanA &orig);
					~HumanA(void);
		HumanA		&operator=(const HumanA &orig);

		void		attack(void) const;

	private:
		Weapon		&_weapon;
		std::string	_name;
};

#endif
