#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
							ScavTrap(void);
							ScavTrap(const ScavTrap &orig);
							~ScavTrap(void);
		ScavTrap			&operator=(const ScavTrap &orig);

							ScavTrap(const std::string &name);

		void				guardGate(void);

	private:
		const static t_uint	_defaultHitPoint = 100;
		const static t_uint	_defaultEnergyPoint = 50;
		const static t_uint	_defaultAttackDamage = 20;
		virtual void		printIdentifier(void);
};

#endif
