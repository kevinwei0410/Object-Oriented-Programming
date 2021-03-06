#include "pch.h"
#include <iostream>
class Point2D
{
private:
	mutable int x;
	mutable int y;
	static const double limit;
	static double value;
	mutable int color;
public:
	Point2D();
	void assignPoint2D(int x, int y);
	void displayPoint2D()const;
	static void setValue(double v);
};
const double Point2D::limit = 10.0;
Point2D::Point2D()
{
	x = 0;
	y = 0;
}
void Point2D::assignPoint2D(int n1, int n2)
{
	x = n1;
	y = n2;
}
void Point2D::displayPoint2D()const 
{
	x = 5; y = 4;
	color = 10;
	std::cout << "(" << x << "," << y << ") = ";
	std::cout << value << std::endl;
}
void Point2D::setValue(double v)
{
	if (v < limit)
		value = v;
	else
		value = limit;
}
double Point2D::value = 0.0;
int main()
{
	const Point2D pt1;
	Point2D pt2;
	pt1.displayPoint2D();
	pt2.displayPoint2D();


	return 0;
}