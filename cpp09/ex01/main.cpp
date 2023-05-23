#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Wrong usage: Ex: ./RPN \"1 2 + 3 * 4 +\"\n";
	}
	try {
		std::string input = argv[1];
		RPN rpn;
		rpn.calculate(input);
		std::cout << rpn;
	} catch (const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
}