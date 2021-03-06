#include "pch.h"
#include <iostream>
#ifndef PI
#define PI 3.14159
#endif
using std::cout; using std::endl; using std::ends;	using std::cin;
class Point2D
{
private:
	int x;
	int y;
public:
	Point2D(int x = 0, int y = 0) { set(x, y); }
	void set(int x, int y) { this->x = x; this->y = y; }
	void display() const { cout << "(" << x << ends << y << ")" << endl; }
	friend class Triangle;
};
class Shape
{
protected:
	int color = 255;
};
class Circle :public virtual Shape
{
private:
	Point2D center;
	double radius;
public:
	Circle(const Point2D &p, double r) { this->radius = r; this->center = p; }
	void draw() {
		center.display();
		cout << "radius : " << radius;
	}
	double area() { return PI * radius*radius; }
};
class Triangle :public virtual Shape
{
private:
	Point2D *vertices;
public:
	Triangle() { vertices = new Point2D[3];  }
	Triangle(const Point2D *vec) { vertices = new Point2D[3];  *vertices = *vec; 
	for (int i = 0; i < 3; i++)
		vertices[i] = vec[i];
	delete vec; }
	void set(int a, int b, int c, int d, int e, int f) { vertices[0].x = a; vertices[0].y = b; vertices[1].x = c; vertices[1].y = d; vertices[2].x = e; vertices[2].y = f; }
	~Triangle() { delete[] vertices; }
	void draw() { vertices->display(); }
	void point() { cout << vertices[0].x << vertices[0].y <<"***"<< vertices[2].x << vertices[2].y << endl; }
	double area() { return 0.5*(vertices[0].x*vertices[1].y + vertices[1].x*vertices[2].y + vertices[2].x*vertices[0].y - vertices[0].y*vertices[1].x - vertices[1].y*vertices[2].x - vertices[2].y*vertices[0].x); }
};
class Circle_in_Triangle : public Circle, public Triangle
{
public:
	Circle_in_Triangle(const Point2D &p, double r, Point2D *vec) :Circle(p, r), Triangle(vec) { ; }
	void draw()
	{
		cout << "Circle's color: " << Circle::color << endl;
		cout << "Triangle's color: " << Triangle::color << endl;
		cout << "Circle_in_Triangle: " << Circle_in_Triangle::color << endl;
		Circle::draw();
		//Triangle::draw();
	}
	double area() { return Triangle::area() - Circle::area(); }
	void area_print()
	{
		cout << "Area of Circle:";
		cout << Circle::area() << endl;
		cout << "Area of Triangle:";
		cout << Triangle::area() << endl;
		cout << "Area of Circuit_in_Triangle:";
		cout << this->area() << endl;
	}
};
int main()
{
	Point2D p;
	p.set(2, 2);
	Point2D *vec = new Point2D[3];
	vec[0].set(10, 9);
	vec[1].set(8, 8);
	vec[2].set(7, 7);
	Circle_in_Triangle ct(p, 1, vec);
	ct.draw();
	cout << endl;
	ct.point();
	cout << endl;
	ct.area_print();

	return 0;
}