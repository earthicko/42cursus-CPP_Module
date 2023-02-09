#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public:
							Weapon(const std::string &newType);
							~Weapon(void);

		const std::string	&getType(void) const;
		void				setType(const std::string &newType);

	private:
		std::string			type;
};

#endif
