#ifndef BITUTILS_HPP
# define BITUTILS_HPP

# define COLUMN_WIDTH 3
# define COLUMN_DIVIDER "|"

void	printBits(unsigned char val);
void	printBits(int val);
void	printBits(float val);
void	prettyPrintBits(int val);
void	prettyPrintBits(float val);

float	composeFloat(int *bits);

#endif
