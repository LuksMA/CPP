#include <iostream>

using namespace std;

class IShape
{
	public:
		virtual int getArea() = 0;
		virtual int getPerimeter() = 0;
};

class Rectangle : public IShape
{
	int length;
	int breadth;
	public:
		Rectangle(int l, int b)
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
			return 2*(length + breadth);
		}
};

class Square : public IShape
{
	int side;
	public:
		Square(int a)
		{
			side = a;
		}
		int getArea()
		{
			return side * side;
		}
		int getPerimeter()
		{
			return 4 * side;
		}
};

int main()
{
	Rectangle rt(7, 4);
	Square s(4);
	cout << "Rectangle :" << endl;
	cout << "Area : " << rt.getArea() << " Perimeter : " << rt.getPerimeter() << endl;
	cout << "Square :" << endl;
	cout << "Area : " << s.getArea() << " Perimeter : " << s.getPerimeter() << endl;
	return 0;
}
