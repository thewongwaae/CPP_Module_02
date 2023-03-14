#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);

int main(void)
{
	{
	const Point a;
	const Point b(10, 0);
	const Point c(0, 10);
	const Point point(1, 1);

	std::cout << "The point( x= " << point.getx() << "\t\ty= " << point.gety() << "\t) is inside the triangle\n" <<
	"\ta( x= " << a.getx() << "\t\ty= " << a.gety() << "\t)\n" <<
	"\tb( x= " << b.getx() << "\ty= " << b.gety() << "\t)\n" <<
	"\tc( x= " << c.getx() << "\t\ty= " << c.gety() << "\t)\n" << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	}
	std::cout << "\n---------------------------------------------------------------------\n" << std::endl;
	{
	Point a(-1.5, -1.5);
	Point b(2.5, 2.5);
	Point c(-1, -2);
	Point point(10, 10);

	std::cout << "The point( x= " << point.getx() << "\ty= " << point.gety() << "\t) is inside the triangle\n" <<
	"\ta( x= " << a.getx() << "\ty= " << a.gety() << "\t)\n" <<
	"\tb( x= " << b.getx() << "\ty= " << b.gety() << "\t)\n" <<
	"\tc( x= " << c.getx() << "\ty= " << c.gety() << "\t)\n" << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	}
	return (0);
}