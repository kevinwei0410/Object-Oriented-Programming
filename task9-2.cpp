#include "pch.h"
#include <iostream>
using namespace std;
class Point2D {
private:
	int x, y;
public:
	Point2D(int n1 = 0, int n2 = 0) :x(n1), y(n2) { ; }
	//Point2D(const Point2D &p2) { this->x = p2.x; this->y = y; }//system will automatically generate ;
	void display() const { cout << x << ends << y << ends; }
	void f(const Point2D&, const Point2D&);
};
class Point4D :public Point2D {
private:
	int z, t;
public:
	Point4D(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0) :Point2D(n1, n2) { z = n3, t = n4; }
	//Point4D(const Point4D &p4) :Point2D(p4) { z = p4.z; t = p4.t; }//system will automatically generate ;
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
//**************************************************
class Car :public Point4D {
private:
	int color, year;
public:
	Car(int n1 = 0, int n2 = 0, int n3 = 0, int n4 = 0) : Point4D(n1, n2, n3, n4) { color = 0, year = 0; }
	Car(const Point4D &p) :Point4D(p) { year = 0; color = 0; }

	void display() const;
	void setColor(const int c) { color = c; }
	void setYear(const int y) { year = y; }
};
void Car::display() const
{
	cout << "color: " << color << endl;
	cout << "year: " << year << endl;
	Point4D::display();
}
int main()
{
	Point4D pt4(1, 2, 3, 4);

	Car c1(pt4);
	c1.setColor(128);
	c1.setYear(2011);
	c1.display();
	cout << endl;
}