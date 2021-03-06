#include "pch.h"
#include <iostream>
using std::cout;
using std::endl;
int sum(int *array, int len)
{
	int n = 0;
	for (int i = 0; i < len; i++)
		n += array[i];
	return n;
}
double sum(double *array, int len)
{
	double n = 0.0;
	for (int i = 0; i < len; i++)
		n += array[i];
	return n;
}
int min(int n1, int n2)
{
	int tmp = n1 < n2 ? n1 : n2;
	return tmp;
}
int min(int n1, int n2, int n3)
{
	int tmp = min(n1, n2);
	return min(tmp, n3);
}
int main()
{
	int array1[5] = { 1,2,3,4,5 };
	cout << "sum(array1) = " << sum(array1, 5) << endl;

	double array2[5] = { 1.1,2.2,3.3,4.4,5.5 };
	cout << "sum(array2) = " << sum(array2, 5) << endl;

	cout << "min(4,3) = " << min(4, 3) << endl;
	cout << "min(1,3,2) = " << min(1, 3, 2) << endl;

	return 0;
}