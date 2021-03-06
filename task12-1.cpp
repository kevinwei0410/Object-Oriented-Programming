#include "pch.h"
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;
template <class T>
T *new1D(int n, T k)
{
	T *vec = new T[n];
	for (unsigned i = 0; i < n; i++)
		vec[i] = k;
	return vec;
}
template <class T>
void delete1D(T *vec)
{
	delete[]vec;
}
template <class T>
void display1D(T *vec, int n)
{
	for (unsigned i = 0; i < n; i++)
		cout << vec[i] << ends;
	cout << endl;
}
int main()
{
	int *ptr = new1D<int>(10, 1);
	display1D<int>(ptr, 10);
	delete1D<int>(ptr);

	double *ptr2 = new1D<double>(10, 3.5);
	display1D<double>(ptr2, 10);
	delete1D<double>(ptr2);
	return 0;
}