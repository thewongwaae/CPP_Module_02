#pragma once
#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point( void );
		Point( const float x, const float y );
		Point( const Point &copy );
		~Point( void );
		Point &operator=( const Point &assign );

		const Fixed getx( void ) const;
		const Fixed gety( void ) const;
};

std::ostream &operator<<( std::ostream &o, const Point point );

#endif