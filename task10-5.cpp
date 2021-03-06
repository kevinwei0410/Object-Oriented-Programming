#include "pch.h"
#include <iostream>
using std::cout; using std::endl; using std::ends;
class Point2D
{
private:
	int x;
	int y;
public:
	Point2D() { x = 0; y = 0; }
	void display() const { cout << "(" << x << ends << y << ")"; }
};
class Shape
{
protected:
	int color;
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
	double area() { ; }
};
class Triangle :public virtual Shape
{
private:
	Point2D *vertices;
public:
	Triangle() { vertices = new Point2D; }
	Triangle(const Point2D *vec) { vertices = new Point2D;  *vertices = *vec; }
	~Triangle() { delete[] vertices; }
	void draw() { vertices->display(); }
	double area() { ; }
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
		Triangle::draw();
	}
};
int main()
{
	Point2D p;
	Point2D *vec = new Point2D[3];

	Circle_in_Triangle ct(p, 0, vec);
	ct.draw();


	return 0;
}