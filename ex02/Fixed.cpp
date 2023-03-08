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

/* Constructors and Deconstructors */
Fixed::Fixed( void ) : _num(0) {}

Fixed::Fixed( const int num ) : _num(num * ft_power(2, this->_bits)) {}

Fixed::Fixed( const float num ) : _num(num * ft_power(2, this->_bits)) {}

Fixed::Fixed( const Fixed &copy ) {
	*this = copy;
}

Fixed::~Fixed( void ) {}

/* Overloaded operators */
Fixed &Fixed::operator=( const Fixed &assign ) {
	this->_num = assign.getRawBits();
	return *this;
}

bool &Fixed::operator>( const Fixed &num ) const {
	bool res = this->toFloat() > num.toFloat();
	return (res);
}

bool &Fixed::operator<( const Fixed &num ) const {
	bool res = this->toFloat() < num.toFloat();
	return (res);
}

bool &Fixed::operator>=( const Fixed &num ) const {
	bool res = this->toFloat() >= num.toFloat();
	return (res);
}

bool &Fixed::operator<=( const Fixed &num ) const {
	bool res = this->toFloat() <= num.toFloat();
	return (res);
}

bool &Fixed::operator==( const Fixed &num ) const {
	bool res = this->toFloat() == num.toFloat();
	return (res);
}

bool &Fixed::operator!=( const Fixed &num ) const {
	bool res = this->toFloat() != num.toFloat();
	return (res);
}

Fixed	&Fixed::operator+( const Fixed &num ) const {
	Fixed res = this->toFloat() + num.toFloat();
	return (res);
}

Fixed	&Fixed::operator-( const Fixed &num ) const {
	Fixed res = this->toFloat() - num.toFloat();
	return (res);
}

Fixed	&Fixed::operator*( const Fixed &num ) const {
	Fixed res = this->toFloat() * num.toFloat();
	return (res);
}

Fixed	&Fixed::operator/( const Fixed &num ) const {
	Fixed res = this->toFloat() / num.toFloat();
	return (res);
}

Fixed	&Fixed::operator++(void) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++( int num ) {
	Fixed	aux;

	aux = *this;

	if (!num)
		num = 1;
	this->setRawBits(this->getRawBits() - num);
	return (aux);
}

Fixed	&Fixed::operator--(void) {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator--( int num ) {
	Fixed	aux;

	aux = *this;

	if (!num)
		num = 1;
	this->setRawBits(this->getRawBits() - num);
	return (aux);
}

const Fixed	&Fixed::min( const Fixed &num1, const Fixed &num2 ) {
	if (num1._num < num2._num)
		return (num1._num);
	return (num2._num);
}

const Fixed	&Fixed::max( const Fixed &num1, const Fixed &num2 ) {
	if (num1._num > num2._num)
		return (num1._num);
	return (num2._num);
}


int Fixed::getRawBits( void ) const {
	return (this->_bits);
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
