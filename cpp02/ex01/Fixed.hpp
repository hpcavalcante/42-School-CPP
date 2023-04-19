#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					value;
		static const int	fractionalBits;
	public:
		Fixed(void);
		Fixed(Fixed const &fixed);
		Fixed(const int number);
		Fixed(const float number);
		Fixed &operator = (Fixed const &fixed);
		~Fixed();
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
};

std::ostream &operator << (std::ostream &out, Fixed const &fn);

#endif