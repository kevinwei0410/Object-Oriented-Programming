#include "pch.h"
#include <iostream>
using namespace std;
class ccomplex {
	double real, imag;
public:
	ccomplex() { real = 0, imag = 0; }
	ccomplex(double r, double i) { real = r, imag = i; }
	void setcomplexnumber(double r, double i) { real = r, imag = i; }
	const friend ccomplex operator+(ccomplex& o1, ccomplex& o2);
	const friend ccomplex operator-(ccomplex & ol);
	const friend ccomplex operator-(ccomplex &o1, ccomplex &o2);
	const ccomplex operator+=(ccomplex & o2);
	const ccomplex operator+(double x);
	const ccomplex operator++();
	const ccomplex operator++(int);
	friend ostream& operator<<(ostream& out, ccomplex& o1);
	friend istream& operator>>(istream&, ccomplex& o1);
	void display() { cout << real << "+" << imag << "i" << endl; }
};
const ccomplex operator+(ccomplex& o1, ccomplex& o2)
{
	return ccomplex(o1.real + o2.real, o1.imag + o2.imag);
}
const ccomplex ccomplex::operator+(double x)
{
	return ccomplex(this->real + x, this->imag);
}
const ccomplex operator-(ccomplex& o1)
{
	return ccomplex(-o1.real, -o1.imag);
}
const ccomplex operator-(ccomplex &o1, ccomplex &o2)
{
	return ccomplex(o1.real - o2.real, o1.imag - o2.imag);
}
const ccomplex ccomplex::operator+=(ccomplex & o2)
{
	return ccomplex(this->real + o2.real, this->imag + o2.imag);
}
const ccomplex ccomplex::operator++()
{
	this->imag++;
	this->real++;
	return *this;
}

const ccomplex ccomplex::operator++(int y)
{
	ccomplex temp = *this;
	this->imag++;
	this->real++;
	return temp;
}
ostream& operator<<(ostream &out, ccomplex &o1)
{
	out << "(" << o1.real << "+" << o1.imag << "i)" << endl;
	return out;
}
istream& operator>>(istream &in, ccomplex &o1)
{
	in >> o1.real >> o1.imag;
	return in;
}
void printMeg(ccomplex &a, ccomplex &b, char operate)
{
	cout << a << operate << b << "=";
}
int main()
{
	ccomplex a(1.0, 7.0), b(9.0, 2.0), c;
	printMeg(a, b, '+');
	c = a + b;
	cout << c << endl;

	printMeg(a, b, '-');
	c = a - b;
	cout << c << endl;

	a.setcomplexnumber(10.0, 1.0);
	b = -a;
	printMeg(a, b, '-');
	c = a - b;
	cout << c << endl;
}