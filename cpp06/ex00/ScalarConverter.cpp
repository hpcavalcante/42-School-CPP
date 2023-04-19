#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string s) {
	int 	i;
	float 	f;
	double 	d;
	std::stringstream 	ss(s);
	std::string			type;
	
	type = ScalarConverter::getType(s);
	std::cout << "Input: " << s << "\n";
	if (s.length() == 1 && isprint(s[0]) && isdigit(s[0]) == 0)
		ScalarConverter::convertChar(s[0]);
	else if (type == "float") {
		ss >> f;
		ScalarConverter::convertFloat(f);
	}
	else if (type == "double") {
		ss >> d;
		ScalarConverter::convertDouble(d);
	}
	else if (type == "int") {
		ss >> i;
		ScalarConverter::convertInt(i);
	}
	else
		std::cout << "Invalid input" << "\n";
}

std::string ScalarConverter::getType(std::string s) {
    char *check;
    strtol(s.c_str(), &check, 10);
    if (*check == '\0')
        return ("int");
    strtod(s.c_str(), &check);
    if (*check == '\0') {
        if (s.find('.') != std::string::npos && s.length() - s.find('.') <= 7)
            return ("float");
        else
            return ("double");
    }
    return ("invalid");
}

void ScalarConverter::convertChar(char c) {
	std::cout << "CONVERTING CHAR: " << c << "\n";
	std::cout << "char: '" << c << "'" << "\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << "float: " << static_cast<float>(c) << "f" << "\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void ScalarConverter::convertInt(int i) {
	std::cout << "CONVERTING INT: " << i << "\n";
	std::cout << "char: ";
	if (i < 0 || i > 127)
		std::cout << "impossible" << "\n";
	else if (i < 32 || i == 127)
		std::cout << "Non displayable" << "\n";
	else
		std::cout << "'" << static_cast<char>(i) << "'" << "\n";

	std::cout << "int: " << i << "\n";
	std::cout << "float: " << static_cast<float>(i) << "f" << "\n";
	std::cout << "double: " << static_cast<double>(i) << "\n";
}

void ScalarConverter::convertFloat(float f) {
    std::cout << "CONVERTING FLOAT: " << f << "\n";
	std::cout << "char: ";
    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
        std::cout << "impossible" << "\n";
    else
        std::cout << "'" << static_cast<char>(f) << "'" << "\n";

    std::cout << "int: ";
    if (std::isnan(f) || std::isinf(f) || f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
        std::cout << "impossible" << "\n";
    else
        std::cout << static_cast<int>(f) << "\n";

    std::cout << "float: " << f << "f" << "\n";
    std::cout << "double: " << static_cast<double>(f) << "\n";
}

void ScalarConverter::convertDouble(double d) {
	std::cout << "CONVERTING DOUBLE: " << d << "\n";
	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << "\n";
	else if (d < 32 || d == 127)
		std::cout << "Non displayable" << "\n";
	else
		std::cout << "'" << static_cast<char>(d) << "'" << "\n";

	std::cout << "int: ";
	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
		std::cout << "impossible" << "\n";
	else
		std::cout << static_cast<int>(d) << "\n";

	std::cout << "float: ";
	if (d < static_cast<double>(FLT_MIN) || d > static_cast<double>(FLT_MAX))
		std::cout << "impossible" << "\n";
	else
		std::cout << static_cast<float>(d) << "f" << "\n";

	std::cout << std::setprecision(10) << "double: " << d << "\n";
}