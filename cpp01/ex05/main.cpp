#include "Harl.hpp"

int main(int argc, char **argv){
	Harl harl;
	std::string option;

	if (argc != 2){
		std::cout << "Usage: ./harl <option>" << std::endl;
		return 0;
	}
	option = argv[1];
	for (int i = 0 ; i < option[i] ; i++)
		option[i] = toupper(option[i]);
	harl.complain(option);
	return 0;
}