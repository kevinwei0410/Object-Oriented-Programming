#include "pch.h"
#include <iostream>
using namespace std;
template <typename T>
class Point2D {
private:
	T x, y;
public:
	Point2D() :x(0), y(0) { ; }
	Point2D(T a, T b) { x = a, y = b; }
	void display() const;
};

template<typename T>
void Point2D<T>::display() const
{
	cout << x << ends << y << endl;
}
int main()
{
	Point2D<int> p1;
	p1.display();

	Point2D<double> p2(1.9, 3.4);
	p2.display();

	return 0;
}