#include "pch.h"
#include <iostream>
using namespace std;
class Complex {
private:
	double real, imag;
public:
	Complex() { ; }
	Complex(double r, double i) { real = r; imag = i; }
	void setComplexNumber(double r, double i) { real = r, imag = i; }
	const Complex operator+(const Complex &o) { return Complex(o.real + real, o.imag + imag); }
	const Complex operator-(const Complex &o) { return Complex(o.real - real, o.imag - imag); }
	//const Complex operator-(const Complex &o) { return Complex(-o.real, -o.imag); }
	const Complex operator+=(const Complex &o) { return Complex(this->real + o.real, this->imag + o.imag); }
	const friend Complex operator*(const Complex &, const Complex&);
	const friend Complex operator/(const Complex &, const Complex&);
	const Complex operator++();
	const Complex operator++(int);
	friend ostream& operator<<(ostream &, const Complex &);
	friend istream& operator>>(istream &, Complex &);
};
inline const Complex operator*(const Complex &o1, const Complex &o2)
{
	double real = o1.real*o2.real - o1.imag*o2.imag;
	double imag = o1.real*o2.imag + o1.imag*o2.real;
	return Complex(real, imag);
}
inline const Complex operator/(const Complex &o1, const Complex &o2)
{
	double real = (o1.real*o2.real + o1.imag*o2.imag) / (o2.real*o2.real + o2.imag *o2.imag);
	double imag = (o1.real*o2.real - o1.imag*o2.imag) / (o2.real*o2.real + o2.imag *o2.imag);
	return Complex(real, imag);
}
inline const Complex Complex::operator++()
{
	return Complex(this->real++, this->imag++);
}
inline const Complex Complex::operator++(int s)
{
	double real = this->real;
	double imag = this->imag;
	this->imag++;
	this->real++;
	return Complex(real, imag);
}
inline ostream& operator<<(ostream &out, const Complex &o)
{
	cout.setf(ios::showpos);
	cout.precision(2);
	out  << "(" << o.real << o.imag << "i)";
	return out;
}
inline istream& operator>>(istream &in, Complex &o)
{
	in >> o.real >> o.imag;
	return in;
}
int main()
{
	Complex a(1.0, 7.0), b(9.0, 2.0), c;
	c = a + b;
	cout << c << endl;
	c = a - b;
	cout << c << endl;
	c = a * b;
	cout << c << endl;
	c = a / b;
	cout << c << endl;
	a.setComplexNumber(10.0, 1.0);
	cout << ++a << endl;
	a.setComplexNumber(10.0, 1.0);
	cout << a++;
	cout << a << endl;
	c += a;
	cout << c << endl;
	return 0;
}