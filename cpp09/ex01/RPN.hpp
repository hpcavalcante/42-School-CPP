#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>


class RPN {
	public:
		RPN();
		RPN(RPN const &other);
		~RPN();

		RPN &operator=(RPN const &other);

		void calculate(std::string input);

		class DivisionByZeroException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Impossible division by zero";
				}
		};
};

std::ostream&    operator<<(std::ostream& o, const RPN& i);

#endif