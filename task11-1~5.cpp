#include "pch.h"
#include <iostream>
#ifndef PI
#define PI 3.14159
#endif
using namespace std;
class Point2D {
protected:
	int *x;
	int *y;
public:
	Point2D(int a = 0, int b = 0) { setPoint2D(a, b); }
	void setPoint2D(int a, int b) { x = new int(a); y = new int(b); }
	virtual ~Point2D() { delete x; delete y; }
	virtual void display() const { cout << "(" << *x << "," << *y << ")" << endl; }
};
class Point4D : public Point2D {
private:
	int *z;
	int *t;
public:
	Point4D(int a = 0, int b = 0, int c = 0, int d = 0) : Point2D(a, b) { z = new int(c); t = new int(d); }
	~Point4D() { delete z; delete t; }
	void display() const { cout << "(" << *x << "," << *y << "," << *z << "," << *t << ")" << endl; }
};
class Shape {
protected:
	int color;
public:
	Shape(int c = 0) { color = c; }
	virtual void draw() = 0;
	virtual double area() { return 0; }
};
class Circle : public Shape {
private:
	Point2D center;
	double radius;
public:
	Circle(const Point2D &object, const double r = 0, const int c = 0) :Shape(c) { center = object;	radius = r; }
	double area() { return PI * radius*radius; }
	void draw() {
		cout << "Circle:" << endl;
		center.display();
		cout << "color:" << color << endl;
		cout << "radius:" << radius << endl;
	}
};
class Polygon : public Shape {
public:
	Polygon(int c = 0) :Shape(c) { ; }
};
class Triangle : public Polygon {
private:
	Point2D *vertices;
public:
	Triangle(Point2D *object) { vertices = object; }
	double area() { return 999; }
	void draw() {
		for (short int i = 0; i < 3; i++)
			vertices[i].display();
	}
};
class Rectangle : public Polygon {
	Point2D *vertices;
public:
	Rectangle(Point2D *object) { vertices = object; }
	double area() { return 444; }
	void draw() {
		for (short int i = 0; i < 4; i++)
			vertices[i].display();
	}
};
int main()
{
	Point2D ptr(3, 4);
	Circle cir(ptr, 5);
	/*cir.draw();
	cout << "area:" << cir.area() << endl;*/

	Point2D *vec = new Point2D[3];
	vec[0].setPoint2D(1, 1);
	vec[1].setPoint2D(1, 6);
	vec[2].setPoint2D(8, 1);
	Triangle tri(vec);
	/*tri.draw();
	cout << "area:" << tri.area() << endl;
	delete[]vec;*/

	vec = new Point2D[4];
	vec[0].setPoint2D(1, 1);
	vec[1].setPoint2D(6, 1);
	vec[2].setPoint2D(6, 6);
	vec[3].setPoint2D(1, 6);
	Rectangle rect(vec);
	/*rect.draw();
	cout << "area:" << rect.area() << endl;*/

	Shape *collection[3];
	collection[0] = &cir;
	collection[1] = &tri;
	collection[2] = &rect;

	cout << "Area of Circle: " << collection[0]->area() << endl;
	cout << "Area of Triangle: " << collection[1]->area() << endl;
	cout << "Area of Rectangle: " << collection[2]->area() << endl;

}