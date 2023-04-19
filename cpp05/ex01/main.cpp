#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./main <grade>\n";
		return (1);
	}
	
	int grade;
	std::stringstream(argv[1]) >> grade;
	Bureaucrat bureaucrat("David Wallace", grade);

	std::cout << "Testing form with a grade too high:\n";
	try {
		Form form("Form", 0, 1);
		std::cout << form;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	std::cout << "\nTesting form with a grade too low:\n";
	try {
		Form form("Form", 151, 1);
		std::cout << form;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}

	std::cout << "\nTesting multiple forms with a given grade:\n";
	try {
		Form form1("Form1", 1, 1);
		bureaucrat.signForm(form1);
		std::cout << form1 << "\n";
		Form form2("Form2", 15, 15);
		bureaucrat.signForm(form2);
		std::cout << form2	<< "\n";
		Form form3("Form3", 30, 30);
		bureaucrat.signForm(form3);
		std::cout << form3 << "\n";
		Form form4("Form4", 45, 45);
		bureaucrat.signForm(form4);
		std::cout << form4 << "\n";
		Form form5("Form5", 60, 60);
		bureaucrat.signForm(form5);
		std::cout << form5 << "\n";
		Form form6("Form6", 75, 75);
		bureaucrat.signForm(form6);
		std::cout << form6 << "\n";
		Form form7("Form7", 90, 90);
		bureaucrat.signForm(form7);
		std::cout << form7 << "\n";
		Form form8("Form8", 105, 105);
		bureaucrat.signForm(form8);
		std::cout << form8 << "\n";
		Form form9("Form9", 120, 120);
		bureaucrat.signForm(form9);
		std::cout << form9 << "\n";
		Form form10("Form10", 135, 135);
		bureaucrat.signForm(form10);
		std::cout << form10 << "\n";
		Form form11("Form11", 150, 150);
		bureaucrat.signForm(form11);
		std::cout << form11	<< "\n";
	}
	catch (std::exception& e) {
		std::cerr << e.what() << "\n";
	}
	return (0);
}
