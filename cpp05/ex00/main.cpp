#include "Bureaucrat.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: ./program <grade>\n";
        return 1;
    }

    int grade;
    std::stringstream(argv[1]) >> grade;

    try {
        Bureaucrat bureaucrat("David Wallace", grade);
        std::cout << bureaucrat << "\n";
        bureaucrat.incrementGrade();
        std::cout << bureaucrat << "\n";
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << "\n";
    } catch (std::exception const &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
