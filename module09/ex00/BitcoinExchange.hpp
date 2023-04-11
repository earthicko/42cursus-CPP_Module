#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>
# include <ctime>

class	BitcoinExchange
{
public:
								BitcoinExchange(const std::string &filepath = "./data.csv");
								BitcoinExchange(const BitcoinExchange &orig);
								~BitcoinExchange(void);
	BitcoinExchange				&operator=(const BitcoinExchange &orig);

	float						getPrice(time_t at) const;

private:
	void						load(const std::string &filepath);
	void						loadLine(const std::string &date, const std::string &price);
	static const std::string	_firstColumn;
	static const std::string	_secondColumn;
	static const char			_delim;
	static const std::string	_dateFormat;
	std::map<time_t, float>		_prices;
};

#endif
