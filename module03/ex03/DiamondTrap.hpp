#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
					DiamondTrap(void);
					DiamondTrap(const DiamondTrap &orig);
					~DiamondTrap(void);
		DiamondTrap	&operator=(const DiamondTrap &orig);

					DiamondTrap(const std::string &name);

		void		whoAmI(void);

	private:
		std::string	_name;
		virtual void	printIdentifier(void);
};

#endif
