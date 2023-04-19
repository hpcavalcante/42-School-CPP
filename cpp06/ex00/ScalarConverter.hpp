#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <iomanip>
# include <cmath>
# include <limits>
# include <climits>
# include <cfloat>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & src);
		~ScalarConverter();
	public:
		static void convert(std::string s);
		static std::string getType(std::string s);
		static void convertChar(char c);
		static void convertInt(int i);
		static void convertFloat(float f);
		static void convertDouble(double d);
};

#endif
