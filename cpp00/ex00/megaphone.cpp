#include <iostream>

int	main(int argc, char **argv){
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	std::string str;	
	for (int i = 1; argv[i]; i++) {
		for (int j = 0; argv[i][j]; j++) {
			str += toupper(argv[i][j]);
		}
	}
	std::cout << str << std::endl;
	return 0;
}
