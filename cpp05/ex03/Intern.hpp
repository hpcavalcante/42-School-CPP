#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
	public:
	  	Intern(void);
		Intern(const Intern &i);
		~Intern(void);

		Intern &operator=(const Intern &i);

		AForm* createShrubberyForm(const std::string target) const;
		AForm* createRobotomyForm(const std::string target) const;
		AForm* createPresidentialForm(const std::string target) const;
		AForm* makeForm(const std::string name, const std::string target);

		class InvalidFormException : public std::exception {
			public:
				const char* what(void) const throw();
  		};
};

#endif