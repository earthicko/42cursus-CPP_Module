#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class	RPN
{
private:
	std::stack<int>	_buffer;

public:
					RPN(void);
					RPN(const RPN &orig);
					~RPN(void);
	RPN				&operator=(const RPN &orig);

	void			process(const std::string &input);
	int				result(void);
};

#endif
