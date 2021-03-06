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
	Matrix() { ; }
	Matrix(const Matrix&);
	void assignDimension(int);
	void assignElements();
	void transposeMatrix();
	void operator=(const Matrix&);
	Matrix addMatrix(const Matrix&);
	Matrix subtractMatrix(const Matrix &);
	Matrix multiplyMatrix(const Matrix&);
	void printMatrix();
};
Matrix::~Matrix()
{
	for (int i = 0; i < capacity; i++)
		delete[]ptr[i];
	delete[]ptr;
}
Matrix::Matrix(const Matrix& mat)
{
	assignDimension(mat.capacity);
	ptr = new int *[mat.capacity];
	for (int i = 0; i < mat.capacity; i++)
		ptr[i] = new int[mat.capacity];
	for (int i = 0; i < mat.capacity; i++)
		for (int j = 0; j < mat.capacity; j++)
			ptr[i][j] = mat.ptr[i][j];
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
void Matrix::operator=(const Matrix &mat)
{
	assignDimension(mat.capacity);
	ptr = new int *[mat.capacity];
	for (int i = 0; i < mat.capacity; i++)
		ptr[i] = new int[mat.capacity];
	for (int i = 0; i < mat.capacity; i++)
		for (int j = 0; j < mat.capacity; j++)
			ptr[i][j] = mat.ptr[i][j];
}
Matrix Matrix::addMatrix(const Matrix &o2)
{
	Matrix ans;
	ans.assignDimension(this->capacity);
	ans.assignElements();
	for (int i = 0; i < capacity; i++)
		for (int j = 0; j < capacity; j++)
			ans.ptr[i][j] = this->ptr[i][j] + o2.ptr[i][j];
	return ans;
}
Matrix Matrix::subtractMatrix(const Matrix &o2)
{
	Matrix ans;
	ans.assignDimension(this->capacity);
	ans.assignElements();
	for (int i = 0; i < capacity; i++)
		for (int j = 0; j < capacity; j++)
			ans.ptr[i][j] = this->ptr[i][j] - o2.ptr[i][j];
	return ans;
}
Matrix Matrix::multiplyMatrix(const Matrix &o2)
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