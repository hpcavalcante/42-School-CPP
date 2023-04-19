#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) 
{
}

PresidentialPardonForm::~PresidentialPardonForm(void) 
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5) 
{
	this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : AForm("PresidentialPardonForm", 25, 5) 
{
	*this = p;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &p) 
{
	this->setTarget(p.getTarget());
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat & executor) const 
{
	if (this->getSigned() == false) {
		throw AForm::NotSignedException();
	}
	else if (executor.getGrade() > this->getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	else {
		std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
	}
}