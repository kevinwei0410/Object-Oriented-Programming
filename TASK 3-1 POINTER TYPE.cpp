#include "pch.h"
#include <iostream>
using namespace std;
typedef struct
{
	int x;
	int y;
	double value;
}Point2D;
void assignPoint2D(Point2D *obj, int n1, int n2, double v)
{
	obj->x = n1;
	obj->y = n2;
	obj->value = v;
}
void displayPoint2D(Point2D *obj)
{
	std::cout << "(" << obj->x << "," << obj->y << ") = ";
	std::cout << obj->value << std::endl;
}
int main()
{
	/*double a = 1.34;
	double *pa = &a;

	cout << "a = " << a << endl;
	cout << "&a = " << &a << endl;
	cout << "*a = " << a << endl;
	cout << "pa = " << pa << endl;
	cout << "&pa = " << &pa << endl;
	cout << "*pa = " << *pa << endl;

	*pa = 6.5;
	cout << "a = " << a << endl;
	cout << "*pa = " << *pa << endl;*/

	Point2D ptArray[10];
	for (int i = 0; i < 10; i++)
	{
		assignPoint2D(&ptArray[i], i, i + 2, i * 10);
		displayPoint2D(&ptArray[i]);
	}

	return 0;
}