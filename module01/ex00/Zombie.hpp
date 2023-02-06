#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
	public:
				Zombie(std::string newName = "");
				Zombie(const Zombie &zombie);
				~Zombie(void);
		Zombie	&operator=(const Zombie &zombie);

		void	announce(void);

	private:
		std::string	name;
};

#endif
