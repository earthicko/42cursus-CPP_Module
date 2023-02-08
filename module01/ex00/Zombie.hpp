#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
				Zombie(std::string newName = "");
				~Zombie(void);

		void	announce(void);

	private:
		std::string	name;
};

#endif
