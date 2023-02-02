#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed
{
	public:
							Fixed(void);
							Fixed(const Fixed &orig);
							~Fixed(void);
		Fixed				&operator=(const Fixed &orig);

							Fixed(const int val);
							Fixed(const float val);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		std::ostream		&operator<<(const Fixed &orig);

	private:
		int					_bits;
		const static int	_nfracts;
};

#endif
