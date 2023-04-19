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

		bool operator< (Fixed const &fixed) const; 
		bool operator> (Fixed const &fixed) const; 
		bool operator>=(Fixed const &fixed) const; 
		bool operator<=(Fixed const &fixed) const; 
		bool operator==(Fixed const &fixed) const; 
		bool operator!=(Fixed const &fixed) const; 

		Fixed operator+(Fixed const &fixed) const;
		Fixed operator-(Fixed const &fixed) const;
		Fixed operator*(Fixed const &fixed) const;
		Fixed operator/(Fixed const &fixed) const;

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static const Fixed &min(Fixed const &a, Fixed const &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);
		static Fixed &min(Fixed &a, Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);

};

std::ostream &operator << (std::ostream &out, Fixed const &fn);

#endif