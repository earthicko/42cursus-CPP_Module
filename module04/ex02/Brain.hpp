#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
	public:
							Brain(void);
							Brain(const Brain &orig);
							~Brain(void);
		Brain				&operator=(const Brain &orig);

		void				setIdea(const std::string &idea, int i);
		const std::string	&getIdea(int i) const;

	private:
		const static int	nIdeas = 100;
		std::string			ideas[nIdeas];
		void				printIndexError(int i) const;
};

#endif
