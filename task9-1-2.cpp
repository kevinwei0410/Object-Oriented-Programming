#include "pch.h"
#include <iostream>
using namespace std;
class Point2D {
private:
	int x, y;
public:
	Point2D(int n1 = 0, int n2 = 0) :x(n1), y(n2) { ; }
	void display() const { cout << x << ends << y << ends; }
	void f(const Point2D&, const Point2D&);
};
class Point4D :public Point2D {
private :
	int z, t;
public:
	Point4D(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0) :Point2D(n1, n2) { z = n3, t = n4; }
	void display() const;

};
void Point4D::display() const
{
	Point2D::display();
	cout << z << ends << t << ends;
}
void Point2D::f(const Point2D &p1, const Point2D &p2)
{
	p1.display();
	cout << endl;
	p2.display();
	cout << endl;
}
int main()
{
	Point2D pt2(3, 4);
	Point4D pt4(1, 2, 3, 4);
	pt4.f(pt2, pt4);
}