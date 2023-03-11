#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed {
	private:
		int					_num;
		static const int	_bits;

	public:
		/* Constructors and Deconstructors */
		Fixed( void );
		Fixed( const int num );
		Fixed( const float num );
		Fixed( const Fixed &copy );
		~Fixed( void );

		/* Overloaded operators */
		Fixed	&operator=( const Fixed &assign );
		bool	operator>( Fixed num ) const;
		bool	operator<( Fixed num ) const;
		bool	operator>=( Fixed num ) const;
		bool	operator<=( Fixed num ) const;
		bool	operator==( Fixed num ) const;
		bool	operator!=( Fixed num ) const;
		Fixed	operator+( Fixed num ) const;
		Fixed	operator-( Fixed num ) const;
		Fixed	operator*( Fixed num ) const;
		Fixed	operator/( Fixed num ) const;
		/* Pre / Post increment operators */
		Fixed	operator++( void );
		Fixed	operator++( int );
		Fixed	operator--( void );
		Fixed	operator--( int );
		/* Min and max */
		static const Fixed	&min( const Fixed &num1, const Fixed &num2 );
		static const Fixed	&max( const Fixed &num1, const Fixed &num2 );

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<( std::ostream &str,  const Fixed &nb );

#endif