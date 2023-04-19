#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {
	std::ifstream		infile;
	std::ofstream		outfile;
	std::stringstream	r_line;
	std::string			c_file;
	std::string			outfile_name;
	std::string			outfile_content;
	size_t				pos;
	size_t				start;

	if (argc != 4) {
		std::cout << "Usage: ./swap [file_name] [string_1] [string_2]" << std::endl;
		return 1;
	}
	
	infile.open(argv[1]);
	
	if (!infile) {
		std::cout << "Error opening file: " << std::endl;
		return 1;
	}
	
	r_line << infile.rdbuf();
	c_file = r_line.str();

	pos = c_file.find(argv[2]);
	start = 0;
	while (pos != std::string::npos) {
		outfile_content += c_file.substr(start, pos - start);
		start = pos + std::string(argv[2]).length();
		outfile_content += argv[3];
		pos = c_file.find(argv[2], start);
	}

	outfile_name = std::string(argv[1]) + ".replace";
	outfile.open(outfile_name.c_str());
	if (outfile.fail()) {
		std::cout << "Error opening file: " << std::endl;
		return 1;
	}
	
	outfile_content += c_file.substr(start, c_file.length() - start);
	outfile << outfile_content;

	infile.close();
	outfile.close();
	return 0;

}
