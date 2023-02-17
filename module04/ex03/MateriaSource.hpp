#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	public:
							MateriaSource(void);
							MateriaSource(const MateriaSource &orig);
							~MateriaSource(void);
		MateriaSource		&operator=(const MateriaSource &orig);

		virtual void		learnMateria(AMateria *m);
		virtual AMateria*	createMateria(const std::string &type);

	private:
		const static int	_nSlots = 4;
		AMateria			*_slot[_nSlots];
};

#endif
