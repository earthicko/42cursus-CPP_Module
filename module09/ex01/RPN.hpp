#ifndef RPN_HPP
#define RPN_HPP

#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN
{
  private:
	enum e_ops
	{
		PLUS = '+',
		MINUS = '-',
		DIVIDE = '/',
		MULTIPLY = '*'
	};
	static const char ops[];
	static double (*const opfunc[])(const double &, const double &);
	std::stack<double> _buffer;
	bool _multiDigitMode;

	int parseOperator(const std::string &input);
	double parseOperand(const std::string &input);
	void doOperation(const int opIdx);

  public:
	RPN(void);
	RPN(const RPN &orig);
	~RPN(void);
	RPN &operator=(const RPN &orig);

	void process(const std::string &input);
	double result(void);

	class ParseFailException : public std::runtime_error
	{
	  public:
		ParseFailException(const std::string &cause);
	};
	class NotEnoughOperandsException : public std::runtime_error
	{
	  public:
		NotEnoughOperandsException(void);
	};
	class NotEnoughOperatorsException : public std::runtime_error
	{
	  public:
		NotEnoughOperatorsException(void);
	};
};

double plusfunc(const double &lhs, const double &rhs);
double minusfunc(const double &lhs, const double &rhs);
double dividefunc(const double &lhs, const double &rhs);
double multiplyfunc(const double &lhs, const double &rhs);

#endif
