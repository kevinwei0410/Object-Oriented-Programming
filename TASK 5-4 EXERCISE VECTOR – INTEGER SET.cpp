#include "pch.h"
#include "iostream"
#include "vector"
#include "algorithm"
#ifndef MAX_SIZE 
#define MAX_SIZE 16
#endif
using namespace std;
class Vec {
	int *ptr;
	int dim;
public:
	Vec() {};
	Vec(int *, int);
	void assign(int *, int);
	void sort();
	int max() { return ptr[dim - 1]; }
	int min() { return ptr[0]; }
	Vec inpendetSet();
	void printVec();
	friend Vec unionSet(const Vec&, const Vec&);
};
Vec::Vec(int *array, int dim)
{
	this->dim = dim;
	ptr = new int[dim];
	for (int i = 0; i < dim; i++)
		ptr[i] = array[i];
}
void Vec::assign(int *array, int dim)
{
	delete[]ptr;
	this->dim = dim;
	ptr = new int[dim];
	for (int i = 0; i < dim; i++)
		ptr[i] = array[i];
}
void Vec::sort()
{
	vector <int> temp(ptr, ptr + dim);
	std::sort(temp.begin(), temp.end());
	delete[] ptr;
	ptr = new int[dim];
	for (int i = 0; i < dim; i++)
		ptr[i] = temp[i];
}
Vec Vec::inpendetSet()
{
	int count = 0;
	Vec ans;
	ans.ptr = new int[MAX_SIZE];
	for (int i = 0; i < dim - 1; i++)
		if (ptr[i] != ptr[i + 1])
			ans.ptr[count++] = ptr[i];
	if (ptr[dim - 1] != ptr[dim - 2])
		ans.ptr[count++] = ptr[dim - 1];
	ans.dim = count;
	return ans;
}
void Vec::printVec()
{
	for (int i = 0; i < this->dim; i++)
		cout << this->ptr[i] << " ";
	cout << endl;
}
Vec unionSet(const Vec &o1, const Vec &o2)
{
	Vec temp;
	temp.dim = o1.dim + o2.dim;
	temp.ptr = new int[o1.dim + o2.dim + 1];
	for (int i = 0; i < o1.dim; i++)
		temp.ptr[i] = o1.ptr[i];
	for (int j = 0; j < o2.dim; j++)
		temp.ptr[o1.dim + j] = o2.ptr[j];
	delete[]o1.ptr;
	delete[]o2.ptr;
	return temp;
}
int main()
{
	int *array1, *array2;
	int dim1 = 0, dim2 = 0;

	array1 = new int[MAX_SIZE];
	array2 = new int[MAX_SIZE];

	int temp;
	while (cin >> temp && temp != -1)
		array1[dim1++] = temp;
	while (cin >> temp && temp != -1)
		array2[dim2++] = temp;


	Vec vec1(array1, dim1);
	Vec vec2;
	vec2.assign(array2, dim2);

	cout << "vec1(sorted): ";
	vec1.sort();
	vec1.printVec();

	cout << "vec2(sorted):";
	vec2.sort();
	vec2.printVec();

	Vec vec3;
	vec3 = unionSet(vec1, vec2);

	cout << "vec3: ";
	vec3.printVec();

	vec3.sort();
	cout << "vec3(sorted) : ";
	vec3.printVec();


	cout << "Min in vec1 and vec2: " << vec3.min() << endl;
	cout << "Max in vec1 and vec2: " << vec3.max() << endl;

	Vec vec4;
	vec4 = vec3.inpendetSet();
	cout << "vec4: ";
	vec4.printVec();

	delete[]array1;
	delete[]array2;
	return 0;
}