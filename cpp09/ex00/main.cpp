#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: wrong usage: ./btc <inputfile>\n";
		return (1);
	}
	BitcoinExchange exchange(argv[1]);
	if (!exchange.checkInput())
		return (1);
	exchange.loadData();
	exchange.runInput();
}