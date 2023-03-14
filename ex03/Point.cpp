#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

// need to go through this loger process to assign properly, as _x and _y are implicitly initialising using the default Fixed constructor
// Point::Point( const float x, const float y ) {
// 	(Fixed) _x = Fixed(x);
// 	(Fixed) _y = Fixed(y);
// }

// this way inits _x and _y by calling the Fixed(float) constructor
Point::Point( const float x, const float y ) : _x(x), _y(y) {}

// same thing for this
// Point::Point( const Point &copy ) {
// 	(Fixed) _x = copy.getx();
// 	(Fixed) _y = copy.gety();
// }

Point::Point( const Point &copy ) : _x(copy.getx()), _y(copy.gety()) {}

Point::~Point( void ) {}

Point &Point::operator=( const Point &assign ) {
	if (this == &assign)
		return *this;

	(Fixed) this->_x = assign.getx();
	(Fixed) this->_y = assign.gety();
	return *this;
}

const Fixed Point::getx( void ) const {
	 return (_x);
}

const Fixed Point::gety( void ) const {
	 return (_y);
}

std::ostream &operator<<( std::ostream &o, const Point point ) {
	o << "x: " << point.getx() << " y: " << point.gety() << std::endl;
	return o;
}