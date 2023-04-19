#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const & cure);
		virtual ~Cure();

		Cure &operator=(Cure const & source);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif