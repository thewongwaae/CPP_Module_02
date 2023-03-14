#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed( void ): _num(0) {}

Fixed::Fixed( const int input ) {
	this->_num = input << this->_bits;
}

Fixed::Fixed( const float input ) {
	this->_num = roundf(input * (1 << this->_bits));
}

Fixed::Fixed( const Fixed &copy ) {
	*this = copy;
}

Fixed::~Fixed( void ) {}

Fixed &Fixed::operator=( const Fixed &src ) {
	if (this != &src)
		this->_num = src.getRawBits();
	return *this;
}


int Fixed::getRawBits( void ) const {
	return (this->_num);
}

void Fixed::setRawBits( const int raw ) {
	this->_num = raw;
}

float Fixed::toFloat( void ) const {
	return ((float)this->_num / (float)(1 << this->_bits));
}

int Fixed::toInt( void ) const {
	return (this->_num >> this->_bits);
}


std::ostream &operator<<(std::ostream &str, Fixed const &fixed)
{
	str << fixed.toFloat();
	return (str);
}
