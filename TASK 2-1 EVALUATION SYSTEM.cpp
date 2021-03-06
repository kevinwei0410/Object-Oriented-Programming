#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
typedef class Student* Studentpointer;
class Student {
private:
	string name, ID;
	int score, time;
public:
	Student() { score = 0; }
	static int id_count;
	void set();
	friend void sort_cout(Studentpointer[]);
};
int Student::id_count = 1;
inline void Student::set()
{
	this->ID = "0" + to_string(this->id_count);
	id_count++;
	cin >> this->name;
	int temp;
	for (int i = 0; i < 9; i++)
	{
		cin >> temp;
		if (temp == 1)
		{
			if (i >= 0 && i < 3)
				this->score += 10;
			if (i >= 3 && i < 6)
				this->score += 20;
			if (i >= 6 && i < 9)
				this->score += 30;
		}
	}
	if (this->score > 100)
		this->score = 100;
	cin >> this->time;

	cout << ID << " " << name << " " << score << " " << time << endl;
}
void sort_cout(Studentpointer school[])
{
	int *rank = new int[5]{ 0,1,2,3,4 }, temp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (school[i]->score > school[j]->score || (school[i]->score == school[j]->score && school[i]->time < school[j]->time))
			{
				temp = rank[i];
				rank[i] = rank[j];
				rank[j] = temp;
			}
		}
	}
	for (int i = 4; i >= 0; i--)
		cout << school[rank[i]]->ID << " " << school[rank[i]]->name << " " << school[rank[i]]->score << " " << school[rank[i]]->time << endl;
}
int main()
{
	Studentpointer school[5];
	for (int i = 0; i < 5; i++)
		school[i] = new Student;
	for (int i = 0; i < 5; i++)
		school[i]->set();
	sort_cout(school);
}
/*
Tom 1 1 1 0 0 1 0 0 1 180
Jean 1 1 0 1 0 1 0 1 0 150
Kevin 0 0 0 1 0 1 0 1 1 90
John 1 0 0 0 0 0 1 1 1 70
Marry 1 1 1 1 1 1 1 0 0 150
*/