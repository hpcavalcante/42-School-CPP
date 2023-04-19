#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm() {
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 145, 137) {
	this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : AForm(s) {
	*this = s;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &s) {
	(void)s;
 	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat & executor) const {
	if (this->getSigned() == false) {
		throw AForm::NotSignedException();
	}
	else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	else {
		std::ofstream outfile (this->getTarget().c_str());   
		std::string tree =
		"	   _-_        \n"
		"    /~~   ~~\\     \n"
		" /~~         ~~\\  \n" 
		"{               } \n"
		" \\  _-     -_  /  \n"
		"   ~  \\\\ //  ~    \n"
		"_- -   | | _- _   \n"
		"  _ -  | |   -_   \n"
		"      // \\\\       \n";
		outfile << tree;
		outfile.close();
	}
}
