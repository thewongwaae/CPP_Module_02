#include "Point.hpp"

static float ft_abs( float num ) {
	return num < 0 ? -num : num;
}

static float areaOf( const Point v1, const Point v2, const Point v3 ) {
	float area = 0.5 * ft_abs((v1.getx().toFloat() * (v2.gety().toFloat() - v3.gety().toFloat())) + (v2.getx().toFloat() * (v3.gety().toFloat() - v1.gety().toFloat())) + (v3.getx().toFloat() * (v1.gety().toFloat() - v2.gety().toFloat())));
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {
	float t = areaOf(a, b, c);
	float t1 = areaOf(a, b, point);
	float t2 = areaOf(b, c, point);
	float t3 = areaOf(c, a, point);

	return t1 + t2 + t3 == t;
}
