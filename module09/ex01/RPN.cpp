#include "RPN.hpp"

const char	RPN::ops[] = {PLUS, MINUS, DIVIDE, MULTIPLY};
double		(* const (RPN::opfunc[]))(const double &, const double &) = {plusfunc, minusfunc, dividefunc, multiplyfunc};

RPN::RPN(void)
	: _buffer()
{
}

RPN::RPN(const RPN &orig)
	: _buffer(orig._buffer)
{
}

RPN::~RPN(void)
{
}

RPN	&RPN::operator=(const RPN &orig)
{
	_buffer = orig._buffer;
	return (*this);
}

int	RPN::parseOperator(const std::string &input)
{
	if (input.length() != 1)
		throw (RPN::ParseFailException(input));
	for (size_t i = 0; i < sizeof(ops) / sizeof(char); i++)
	{
		if (input[0] == ops[i])
			return (i);
	}
	throw (RPN::ParseFailException(input));
}

double	RPN::parseOperand(const std::string &input)
{
	std::stringstream	buf;
	double					val;

	if (input.length() != 1)
		throw (RPN::ParseFailException(input));
	buf.str(input);
	buf >> val;
	if (buf.fail())
		throw (RPN::ParseFailException(input));
	return (val);
}

void	RPN::doOperation(const int opIdx)
{
	double	lhs;
	double	rhs;
	double	res;

	if (_buffer.size() < 2)
		throw (RPN::NotEnoughOperandsException());
	rhs = _buffer.top();
	_buffer.pop();
	lhs = _buffer.top();
	_buffer.pop();
	res = (opfunc[opIdx])(lhs, rhs);
	_buffer.push(res);
}

void	RPN::process(const std::string &input)
{
	int	opIdx;
	int	operand;

	try
	{
		opIdx = parseOperator(input);
		doOperation(opIdx);
		return ;
	}
	catch(const RPN::ParseFailException &e)
	{
		(void)e;
	}
	operand = parseOperand(input);
	_buffer.push(operand);
}

double	RPN::result(void)
{
	double	res;

	if (_buffer.size() != 1)
		throw (RPN::NotEnoughOperatorsException());
	res = _buffer.top();
	_buffer.pop();
	return (res);
}

RPN::ParseFailException::ParseFailException(const std::string &cause)
	: std::runtime_error(std::string("Invalid input: ") + cause)
{
}

RPN::NotEnoughOperandsException::NotEnoughOperandsException(void)
	: std::runtime_error("Not enough operands.")
{
}

RPN::NotEnoughOperatorsException::NotEnoughOperatorsException(void)
	: std::runtime_error("Not enough operators.")
{
}

double	plusfunc(const double &lhs, const double &rhs)
{
	return (lhs + rhs);
}

double	minusfunc(const double &lhs, const double &rhs)
{
	return (lhs - rhs);
}

double	dividefunc(const double &lhs, const double &rhs)
{
	return (lhs / rhs);
}

double	multiplyfunc(const double &lhs, const double &rhs)
{
	return (lhs * rhs);
}
