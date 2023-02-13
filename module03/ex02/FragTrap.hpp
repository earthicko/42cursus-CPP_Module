#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
							FragTrap(void);
							FragTrap(const FragTrap &orig);
							~FragTrap(void);
		FragTrap			&operator=(const FragTrap &orig);

							FragTrap(const std::string &name);

		void				highFivesGuys(void);

	private:
		const static t_uint	_defaultHitPoint = 100;
		const static t_uint	_defaultEnergyPoint = 100;
		const static t_uint	_defaultAttackDamage = 30;
		virtual void		printIdentifier(void);
};

#endif
