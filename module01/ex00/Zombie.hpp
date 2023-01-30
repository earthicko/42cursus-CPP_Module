#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
		Zombie		(void);
		Zombie		(const Zombie &zombie);
		~Zombie		(void);
		Zombie		&operator=(const Zombie &zombie);

		Zombie		(std::string newName);

		void		announce(void);
	
	private:
		std::string	name;
};

#endif
