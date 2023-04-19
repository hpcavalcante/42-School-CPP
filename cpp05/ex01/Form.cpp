#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(1), _gradeToExecute(1)
{
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

Form &Form::operator=(const Form &copy)
{
	static_cast<std::string>(this->_name) = copy.getName();
	const_cast<int&>(this->_gradeToSign) = copy.getGradeToSign();
	const_cast<int&>(this->_gradeToExecute) = copy.getGradeToExecute();
	this->_signed = copy.getSigned();
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << "\n";
	form.getSigned() ? out << "Form is: Signed\n" : out << "Form is: Unsigned\n";
	out << "Grade to sign: " << form.getGradeToSign() << "\n";
	out << "Grade to execute: " << form.getGradeToExecute() << "\n";
    return out;
}
