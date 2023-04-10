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
	BitcoinExchange			&operator=(const BitcoinExchange &orig);

	float					getPrice(time_t at);

private:
	void					load(const std::string &filepath);
	std::map<time_t, float>	_prices;
};

#endif
