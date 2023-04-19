#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &copy)
{
	static_cast<std::string>(this->_name) = copy.getName();
	const_cast<int&>(this->_gradeToSign) = copy.getGradeToSign();
	const_cast<int&>(this->_gradeToExecute) = copy.getGradeToExecute();
	this->_signed = copy.getSigned();
	this->setTarget(copy.getTarget());
	return (*this);
}

AForm::~AForm()
{
}

const std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const std::string AForm::getTarget(void) const {
	return this->_target;
}

void AForm::setTarget(std::string target) {
	this->_target = target;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form hasn't been signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form: " << form.getName() << "\n";
	form.getSigned() ? out << "Form is: Signed\n" : out << "Form is: Unsigned\n";
	out << "Grade to sign: " << form.getGradeToSign() << "\n";
	out << "Grade to execute: " << form.getGradeToExecute() << "\n";
    return out;
}

