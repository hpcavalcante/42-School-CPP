#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm() {
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : AForm(r) {
	*this = r;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &r) {
	this->setTarget(r.getTarget());
 	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat & executor) const {
	if (this->getSigned() == false) {
		throw AForm::NotSignedException();
	}
	else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	else {
		unsigned int seed = static_cast<unsigned int>(time(NULL));
  		int randomizer = rand_r(&seed) % (10);
		if (randomizer > 4) {
			std::cout << "Bzzzz, " << this->getTarget() << " has been robotomized!\n";
		}
		else {
			std::cout << "Bzzzz, Robotomization has failed!\n";
		}
	}
}