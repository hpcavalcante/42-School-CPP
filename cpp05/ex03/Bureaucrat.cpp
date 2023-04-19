#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name)
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other) {
		_grade = other._grade;	
	}
	return *this;
}

std::string const	&Bureaucrat::getName() const
{
	return _name;
}

int					Bureaucrat::getGrade() const
{
	return _grade;
}

void				Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void				Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void				Bureaucrat::signForm(AForm &f)
{
	try {
		f.beSigned(*this);
		std::cout << _name << " signs " << f.getName() << "\n";
	} catch (std::exception &e) {
		std::cout << _name << " cannot sign " << f.getName() << " because " << e.what() << "\n";
	}
}

void		Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << "\n";
	} catch (std::exception &e) {
		std::cout << _name << " cannot execute " << form.getName() << " because " << e.what() << "\n";
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return out;
}
