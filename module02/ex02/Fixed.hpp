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
		static int			getNFracts(void);
		float				toFloat(void) const;
		int					toInt(void) const;

		bool				operator>(const Fixed &other) const;
		bool				operator<(const Fixed &other) const;
		bool				operator>=(const Fixed &other) const;
		bool				operator<=(const Fixed &other) const;
		bool				operator==(const Fixed &other) const;
		bool				operator!=(const Fixed &other) const;
		Fixed				operator+(const Fixed &other) const;
		Fixed				operator-(const Fixed &other) const;
		Fixed				operator*(const Fixed &other) const;
		Fixed				operator/(const Fixed &other) const;
		Fixed				&operator++(void);
		Fixed				operator++(int);
		Fixed				&operator--(void);
		Fixed				operator--(int);
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

	private:
		int					_bits;
		const static int	_nfracts;
		const static int	_subnormalOffset;

		int					toFloatSetExp(int idxFirstBit, int *bitrepr) const;
		void				toFloatSetNormalMantissa(int val, int shift, int *bitrepr) const;
		void				toFloatSetSubnormalMantissa(int val, int *bitrepr) const;
};

std::ostream	&operator<<(std::ostream &os, const Fixed& fixed);

#endif
