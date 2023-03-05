#include "Fixed.hpp"

static float ft_power( float num, int exp )
{
	float	res;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		num = 1 / num;
		exp *= -1;
	}
	res = num;
	while (--exp)
		res *= num;
	return (res);
}

const int Fixed::_bits = 8;


Fixed::Fixed( void ) : _num(0) {}

Fixed::Fixed( const int num ) : _num(num * ft_power(2, this->_bits)) {}

Fixed::Fixed( const float num ) : _num(num * ft_power(2, this->_bits)) {}

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

float Fixed::toFloat( void ) const {
	return (this->_num * ft_power(2, -this->_bits));
}

int Fixed::toInt( void ) const {
	return (this->_num * ft_power(2, -this->_bits));
}

std::ostream &operator<<( std::ostream &str,  const Fixed &nb ) {
	return (str << nb.toFloat());
}
