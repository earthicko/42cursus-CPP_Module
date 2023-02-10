#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

typedef unsigned int	t_uint;

class ClapTrap
{
	public:
							ClapTrap(void);
							ClapTrap(const ClapTrap &orig);
							~ClapTrap(void);
		ClapTrap			&operator=(const ClapTrap &orig);

							ClapTrap(const std::string &name);

		void				attack(const std::string &target);
		void				takeDamage(t_uint amount);
		void				beRepaired(t_uint amount);

	private:
		std::string			_name;
		t_uint				_hitPoint;
		t_uint				_energyPoint;
		t_uint				_attackDamage;
		const static t_uint	_defaultHitPoint = 10;
		const static t_uint	_defaultEnergyPoint = 10;
		const static t_uint	_defaultAttackDamage = 0;
		void				printIdentifier(void);
		void				printStatus(void);
};

#endif
