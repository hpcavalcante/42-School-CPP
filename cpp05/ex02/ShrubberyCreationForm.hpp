#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	private:
		std::string target;
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm(const ShrubberyCreationForm &s);

		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &s);

		void execute(Bureaucrat const & executor) const;
};

#endif