#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed( void ) : _num(0) {}

Fixed::Fixed( const Fixed &copy ) {
	*this = copy;
}

Fixed &Fixed::operator=( const Fixed &assign ) {
	this->_num = assign.getRawBits();
	return *this;
}

Fixed::~Fixed( void ) {}

int Fixed::getRawBits( void ) const {
	return (this->_num);
}

void Fixed::setRawBits( const int raw ) {
	this->_num = raw;
}