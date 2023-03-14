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
