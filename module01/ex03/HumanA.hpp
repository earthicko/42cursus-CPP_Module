#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
					HumanA(const std::string &name, const Weapon &weapon);
					HumanA(const HumanA &orig);
					~HumanA(void);
		HumanA		&operator=(const HumanA &orig);

		void		attack(void);

	private:
		Weapon		_weapon;
		std::string	_name;
};

#endif
