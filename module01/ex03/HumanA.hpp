#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
						HumanA(const std::string &name, const Weapon &weapon);
						~HumanA(void);

		void			attack(void) const;

	private:
		const Weapon	&_weapon;
		std::string		_name;
};

#endif
