#include "pch.h"
#include <iostream>
#include <string>
#define MAX(x, y)(x)>(y)?(x):(y)
#define MIN(x, y)(x)<(y)?(x):(y)
using namespace std;
typedef struct{
	int *data;
	int length;
	bool sign;
}BIGNUMBER;
void ReadTextFile(BIGNUMBER &a)
{
	string temp;
	cin >> temp;
	if (temp[0] == '-')
	{
		a.length = temp.size() - 1;
		a.data = new int[a.length]{ 0 };
		for (int i = 0; i < a.length; i++)
			a.data[i] = (temp[a.length - i - 1] - '0');
		a.sign = true;
	}
	else
	{
		a.length = temp.size();
		a.data = new int[a.length]{ 0 };
		for (int i = 0; i < a.length; i++)
			a.data[i] = (temp[a.length - i - 1] - '0');
		a.sign = false;
	}
}
BIGNUMBER& BigNumberOperation(const BIGNUMBER &a, const BIGNUMBER &b, const char &c)
{
	BIGNUMBER ans;
	if (c == '+')
	{
		if (a.sign == b.sign)
		{
			int min = MIN(a.length, b.length);
			ans.length = MAX(a.length, b.length);
			ans.data = new int[ans.length]{ 0 };
			ans.sign = a.sign;
			for (int i = 0; i < min; i++)
				ans.data[i] = a.data[i] + b.data[i];
			for (int i = min; i < a.length; i++)
				ans.data[i] = a.data[i];
			for (int i = min; i < b.length; i++)
				ans.data[i] = b.data[i];
		}
		for (int i = 0; i < ans.length; i++)
			if (ans.data[i] >= 10)
			{
				ans.data[i] = ans.data[i] - 10;
				ans.data[i + 1]++;
			}
	}
	return ans;
}
ostream& operator<<(ostream &out, const BIGNUMBER &object)
{
	if (object.sign)
		out << '-';
	for (int i = object.length - 1; i >= 0; i--)
		out << object.data[i];
	return out;
}
int main()
{
	//cin >> 12443
	//cin >> 5467755
	BIGNUMBER a, b;

	ReadTextFile(a);
	ReadTextFile(b);

	BIGNUMBER results[2];

	results[0] = BigNumberOperation(a, b, '+');
	//results[1] = BigNumberOperation(a, b, '-');

	cout << endl << results[0] << endl;
	//cout << results[1] << endl;
}