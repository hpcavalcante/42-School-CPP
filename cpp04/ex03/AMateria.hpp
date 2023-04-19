#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
		unsigned int _xp;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & materia);
		virtual ~AMateria();

		AMateria &operator=(AMateria const & source);

		std::string const & getType() const;

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif