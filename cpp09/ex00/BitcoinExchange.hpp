#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>
#include <limits.h>

class BitcoinExchange {
	private:
		std::map<std::string, double> _database;
		std::string _nameFile;
		std::string _inputFile;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(std::string nameFile);
		BitcoinExchange(const BitcoinExchange &src);

		BitcoinExchange& operator=(const BitcoinExchange& src);

		void loadData();
		void runInput();
		bool checkInput();
		bool checkDate(std::string date);
		bool checkIfExist(std::string date);
		bool isNumeric(const std::string& s);
		std::string minusDate(std::string date);
};
    std::ostream&    operator<<(std::ostream& o, const BitcoinExchange& i);

#endif