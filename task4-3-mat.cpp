#include "pch.h"
#include "iostream"
#include "stdlib.h"
using std::cout;
using std::endl;
class Matrix {
	int capacity;
	int **ptr;
public:
	~Matrix();
	void assignDimension(int);
	void assignElements();
	void transposeMatrix();
	Matrix addMatrix(Matrix);
	Matrix subtractMatrix(Matrix);
	Matrix multiplyMatrix(Matrix);
	void printMatrix();
};
Matrix::~Matrix()
{
	cout << capacity;
	for (int i = 0; i < capacity; i++)
		delete []ptr[i];
	delete[]ptr;
}
void Matrix::assignDimension(int capacity)
{
	this->capacity = capacity;
}
void Matrix::assignElements() {
	ptr = new int *[capacity];
	for (int i = 0; i < capacity; i++)
		ptr[i] = new int[capacity];
	for (int i = 0; i < capacity; i++)
		for (int j = 0; j < capacity; j++)
			ptr[i][j] = rand() % 10 + 1;
}
void Matrix::transposeMatrix()
{
	for (int i = 0; i < capacity; i++)
		for (int j = i + 1; j < capacity; j++)
		{
			int temp = ptr[i][j];
			ptr[i][j] = ptr[j][i];
			ptr[j][i] = temp;
		}	
}
Matrix Matrix::addMatrix(Matrix o2)
{
	Matrix ans;
	ans.assignDimension(this->capacity);
	ans.assignElements();
	for (int i = 0; i < capacity; i++)
		for (int j = 0; j < capacity; j++)
			ans.ptr[i][j] = this->ptr[i][j] + o2.ptr[i][j];
	return ans;
}
Matrix Matrix::subtractMatrix(Matrix o2)
{
	Matrix ans;
	ans.assignDimension(this->capacity);
	ans.assignElements();
	for (int i = 0; i < capacity; i++)
		for (int j = 0; j < capacity; j++)
			ans.ptr[i][j] = this->ptr[i][j] - o2.ptr[i][j];
	return ans;
}
Matrix Matrix:: multiplyMatrix(Matrix o2)
{
	Matrix ans;
	ans.assignDimension(this->capacity);
	ans.assignElements();
	for (int i = 0; i < capacity; i++)
		for (int j = 0; j < capacity; j++)
		{
			int temp;
			for (int k = 0; k < capacity; k++)
				temp = this->ptr[i][k] * o2.ptr[k][j];
			ans.ptr[i][j] = temp;
		}
	return ans;
}
void Matrix::printMatrix()
{
	cout << "[";
	for (int i = 0; i < capacity; i++)
	{
		for (int j = 0; j < capacity - 1; j++)
			cout << ptr[i][j] << std::ends;
		if (i != capacity - 1)
			cout << ptr[i][capacity - 1] << ";" << std::ends;
	}
	cout << ptr[capacity - 1][capacity - 1] << "];" << endl;
}
int main()
{
	int n = 3;
	Matrix A, B, C;
	A.assignDimension(n);
	A.assignElements();
	B.assignDimension(n);
	B.assignElements();
	cout << "A = ";
	A.printMatrix();
	cout << "B = ";
	B.printMatrix();
	cout << "A’ = ";
	A.transposeMatrix();
	A.printMatrix();
	cout << "B’ = ";
	B.transposeMatrix();
	B.printMatrix();

	A.transposeMatrix();
	B.transposeMatrix();//recover


	cout << "A + B = ";
	C = A.addMatrix(B);
	C.printMatrix();
	cout << "A - B = ";
	C = A.subtractMatrix(B);
	C.printMatrix();
	cout << "A * B = ";
	C = A.multiplyMatrix(B);
	C.printMatrix();
}