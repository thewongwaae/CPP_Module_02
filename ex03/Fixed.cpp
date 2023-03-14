#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed( void ) : _num(0) {}

Fixed::Fixed( const int num ) {
	_num = num << _bits;
}

Fixed::Fixed( const float num ) {
	_num = roundf(num * (1 << _bits));
}

Fixed::Fixed( const Fixed &copy ) {
	*this = copy;
}

Fixed::~Fixed( void ) {}


Fixed &Fixed::operator=( const Fixed &assign ) {
	if (this != &assign)
		_num = assign.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed num) const
{
	return (this->toFloat() > num.toFloat());
}

bool	Fixed::operator<(Fixed num) const
{
	return (this->toFloat() < num.toFloat());
}

bool	Fixed::operator>=(Fixed num) const
{
	return (this->toFloat() >= num.toFloat());
}

bool	Fixed::operator<=(Fixed num) const
{
	return (this->toFloat() <= num.toFloat());
}

bool	Fixed::operator==(Fixed num) const
{
	return (this->toFloat() == num.toFloat());
}

bool	Fixed::operator!=(Fixed num) const
{
	return (this->toFloat() != num.toFloat());
}

Fixed	Fixed::operator+(Fixed num) const
{
	return (this->toFloat() + num.toFloat());
}

Fixed	Fixed::operator-(Fixed num) const
{
	return (this->toFloat() - num.toFloat());
}

Fixed	Fixed::operator*(Fixed num) const
{
	return (this->toFloat() * num.toFloat());
}

Fixed	Fixed::operator/(Fixed num) const
{
	return (this->toFloat() / num.toFloat());
}

Fixed	Fixed::operator++()
{
	_num++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp = *this;
	++_num;
	return (tmp);
}

Fixed	Fixed::operator--()
{
	_num--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp = *this;
	--_num;
	return (tmp);
}

const Fixed	&Fixed::min( const Fixed &num1, const Fixed &num2 ) {
	if (num1.toFloat() <= num2.toFloat())
		return (num1);
	return (num2);
}

const Fixed	&Fixed::max( const Fixed &num1, const Fixed &num2 ) {
	if (num1.toFloat() >= num2.toFloat())
		return (num1);
	return (num2);
}


int Fixed::getRawBits( void ) const {
	return (this->_bits);
}

void Fixed::setRawBits( const int raw ) {
	this->_num = raw;
}

float Fixed::toFloat( void ) const {
	return ((float)_num / (float)(1 << _bits));
}

int Fixed::toInt( void ) const {
	return (_num >> _bits);
}

std::ostream &operator<<( std::ostream &str,  const Fixed &nb ) {
	return (str << nb.toFloat());
}
