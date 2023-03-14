#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int					_num;
		static const int	_bits;

	public:
		Fixed( void ); // constructor
		Fixed( const int num );
		Fixed( const float num );
		Fixed( const Fixed &copy ); // copy constructor
		Fixed &operator=( const Fixed &assign ); // assignment operator
		~Fixed( void ); // deconstructor

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator<<( std::ostream &str,  const Fixed &nb );

#endif