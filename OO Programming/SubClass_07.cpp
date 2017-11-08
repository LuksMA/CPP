#include <iostream>

using namespace std;

class Rectangle
{
	int length;
	int breadth;
	public:
		Rectangle( int l, int b )
		{
			length = l;
			breadth = b;
		}
		int getArea()
		{
			return length * breadth;
		}
		int getPerimeter()
		{
			return 2*( length + breadth );
		}
};

class Square : public Rectangle
{
	public:
		Square( int a ) : Rectangle( a, a )
		{ }
};

int main()
{
	Square s(2);
	int area, p;
	area = s.getArea();
	p = s.getPerimeter();
	cout << "Area : " << area << endl;
	cout << "Perimeter : " << p << endl;
	return 0;
}
