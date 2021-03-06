#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;
class Complex {
private:
	double x, y;
public:
	Complex() { ; }
	Complex(double x, double y) { this->x = x, this->y = y; }
	const Complex operator+(Complex &o2) { return Complex(this->x + o2.x, this->y + o2.y); }
	const Complex operator-(Complex &o2) { return Complex(this->x - o2.x, this->y - o2.y); }
	const friend Complex operator*(Complex &, Complex &);
	const friend Complex operator/(Complex &, Complex &);
	friend istream& operator>>(istream &, Complex &);
	friend ostream& operator<<(ostream &, Complex &);
};
const Complex operator*(Complex &o1, Complex &o2)
{
	double real, imag;
	real = o1.x*o2.x - o1.y*o2.y;
	imag = o1.x*o2.y + o1.y*o2.x;
	return Complex(real, imag);
}
const Complex operator/(Complex &o1, Complex &o2)
{
	double real, imag;
	real = (o1.x*o2.x + o1.y*o2.y) / (o2.x*o2.x + o2.y*o2.y);
	imag = (o1.x*o2.y - o1.y*o2.x) / (o2.x*o2.x + o2.y*o2.y);
	return Complex(real, imag);
}
istream& operator>>(istream &in, Complex &o1)
{
	cin >> o1.x >> o1.y;
	return in;
}
ostream& operator<<(ostream &out, Complex &o1)
{
	out << fixed << setprecision(1) << "(" << o1.x << "," << o1.y << ")" << endl;
	return out;
}
int main()
{
	Complex o1, o2, o3;
	cin >> o1 >> o2; // 1 7 9 2
	o3 = (o1 + o2);
	cout << o3;
	o3 = (o1 - o2);
	cout << o3;
	o3 = (o1 * o2);
	cout << o3;
	o3 = (o1 / o2);
	cout << o3;
}