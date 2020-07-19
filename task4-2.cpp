#include "pch.h"
#include <iostream>
using namespace std;
class point {
private:
	int x, y;
	double value;
public:
	void setcoord(int, int);
	void setvalue(double);
	int getcoordx(void) { return x; }
	int getcoordy(void) {return y;}
	double getvalue(void) { return value; }
};
int main()
{
	point a;
	a.setcoord(1, 3);
	cout << "a(x, y) = " << a.getcoordx() << ends << a.getcoordy() << endl;
	point *b = new point;
	b->setvalue(5);
	cout << "value of b id " << b->getvalue() << endl;
}
void point::setcoord(int x, int y)
{
	this->x = x;
	this->y = y;
}

void point::setvalue(double value)
{
	this->value = value;
}