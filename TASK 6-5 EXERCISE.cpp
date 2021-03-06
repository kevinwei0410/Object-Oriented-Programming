#include "pch.h"
#include <iostream>
using namespace std;
class quadrangle {
public:
	class vertex {
	friend class quadrangle;
	public:
		vertex(int x = 0, int y = 0) { this->x = x; this->y = y; }
		void display() const { cout << "(" << x << "," << y << ")" << endl; }
		void move(const vertex &v) { this->x += v.x; this->y += v.y; }
	private:
		int x, y;
	};
	static const vertex origin;
	void draw() const;
	void move(const vertex &v);
	quadrangle(const vertex&, const vertex&);
	quadrangle(const vertex&, const vertex&, const vertex&, const vertex&);
private:
	vertex ver1, ver2, ver3, ver4;
};
inline void quadrangle::draw() const
{
	cout << "v1:";
	this->ver1.display();
	cout << "v2:";
	this->ver2.display();
	cout << "v3:";
	this->ver3.display();
	cout << "v4:";
	this->ver4.display();
	cout << endl;
}
inline void quadrangle::move(const vertex &v)
{
	this->ver1.vertex::move(v);
	this->ver2.vertex::move(v);
	this->ver3.vertex::move(v);
	this->ver4.vertex::move(v);
}
quadrangle::quadrangle(const vertex &v1, const vertex &v2)
{
	ver1 = v1;
	ver2.x = v2.x;
	ver2.y = v1.y;
	ver3 = v2;
	ver4.x = v1.x;
	ver4.y = v2.y;
}
quadrangle::quadrangle(const vertex &v1, const vertex &v2, const vertex &v3, const vertex &v4)
{
	ver1 = v1;
	ver2 = v2;
	ver3 = v3;
	ver4 = v4;
}
int main()
{
	quadrangle q1(quadrangle::vertex(0, 0), quadrangle::vertex(3, 2), quadrangle::vertex(10, 7), quadrangle::vertex(8, 10));
	quadrangle q2(quadrangle::vertex(3, 6), quadrangle::vertex(10, 9));
	cout << "q1 information" << endl;
	q1.draw();
	cout << endl;
	cout << "q2 information" << endl;
	q2.draw();
	cout << endl;
	cout << "q1 move to (5,5) " << endl;
	q1.move(quadrangle::vertex(5, 5));
	cout << "q1 information" << endl;
	q1.draw();
	cout << endl;
	cout << "q2 move to (-1,2) " << endl;
	q2.move(quadrangle::vertex(-1, 2));
	cout << "q2 information" << endl;
	q2.draw();
	cout << endl;
}