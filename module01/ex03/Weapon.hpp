#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
							Weapon(std::string newType);
							~Weapon(void);

		const std::string	&getType(void) const;
		void				setType(std::string newType);

	private:
		std::string			type;
};

#endif
