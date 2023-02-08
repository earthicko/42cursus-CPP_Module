#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
							Weapon(void);
							Weapon(const Weapon &weapon);
							~Weapon(void);
		Weapon				&operator=(const Weapon &weapon);

							Weapon(std::string newType);

		const std::string	&getType(void) const;
		void				setType(std::string newType);

	private:
		std::string			type;
};

#endif
