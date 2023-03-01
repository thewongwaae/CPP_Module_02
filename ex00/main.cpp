#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a; // constructor
	Fixed b( a ); // copy constructor
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	return 0;
}