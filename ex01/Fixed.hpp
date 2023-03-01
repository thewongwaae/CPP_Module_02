#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
	private:
		int					_num;
		static const int	_bits;

	public:
		Fixed( void ); // constructor
		Fixed( const Fixed &copy ); // copy constructor
		Fixed &operator=( const Fixed &assign ); // assignment operator
		~Fixed( void ); // deconstructor

		int		getRawBits( void ) const;
		void	setRawBits( const int raw );
};

#endif