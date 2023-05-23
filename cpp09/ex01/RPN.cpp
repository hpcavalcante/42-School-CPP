#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(RPN const &other) {
	*this = other;
}

RPN::~RPN() {
}

RPN &RPN::operator=(RPN const &other) {
	if (this != &other) {
	}
	return *this;
}

void RPN::calculate(std::string input) {
    std::stack<int> stack;
    std::string::iterator it = input.begin();
    std::string::iterator ite = input.end();

    while (it != ite) {
        if (std::isdigit(*it)) {
            stack.push(std::atoi(&(*it)));
            while (std::isdigit(*it)) {
                it++;
            }
        } else if (*it == '+' || *it == '-' || *it == '*' || *it == '/' || *it == '%') {
            if (stack.size() < 2) {
                std::cout << "Not enough values in stack\n";
                return;
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            if (*it == '+') {
                stack.push(a + b);
            } else if (*it == '-') {
                stack.push(a - b);
            } else if (*it == '*') {
                stack.push(a * b);
            } else if (*it == '/') {
				if (a == 0 || b == 0) {
					throw DivisionByZeroException();
				}
                stack.push(a / b);
            } else if (*it == '%') {
                stack.push(a % b);
            }
        } else if (*it != ' ') {
            std::cout << "Invalid character\n";
            return;
        }
        it++;
    }
    if (stack.size() != 1) {
        std::cout << "Invalid expression\n";
        return;
    }
    std::cout << stack.top() << std::endl;
}


std::ostream&    operator<<(std::ostream& o, const RPN& i) {
	(void)i;
	return o;
}