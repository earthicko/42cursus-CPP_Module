#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
							Fixed(void);
							Fixed(const Fixed &orig);
							~Fixed(void);
		Fixed				&operator=(const Fixed &orig);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

	private:
		int					_bits;
		const static int	_nfracts;
};

#endif
