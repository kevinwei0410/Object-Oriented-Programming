#include "pch.h"
#include <iostream>
using namespace std;
class Complex {
private:
	double x, y;
public:
	Complex() { ; }
	Complex(double x, double y) { this->x = x; this->y = y; }
	void printComplex() const { cout << "(" << x << "," << y << ")"; }
	const Complex& add(const Complex &o);

};
const Complex& Complex::add(const Complex &o)
{
	Complex ans;
	ans.x = x + o.x;
	ans.y = y + o.y;
	return ans;
}
int main()
{
	Complex a(1.0, 7.0), b(9.0, 2.0), c; // create three Complex objects
	a.printComplex(); // output object a
	cout << " + ";
	b.printComplex(); // output object b
	cout << " = ";
	c = a.add(b); // invoke add function and assign to object c
	c.printComplex(); // output object c
	cout << endl;
	Complex d(c); // use copy constructor to create object d
	d.printComplex(); // output object d
	return 0;
}