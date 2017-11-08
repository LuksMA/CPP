/// Suppose we have a 'Student' class and while making its object, we want to pass a name of it and if nothing is passed then the name should be "unknown".
#include <iostream>
#include <string>

using namespace std;

class Student
{
	string name;
	public:
		Student( string n )
		{
			name = n;
		}
		Student()
		{
			name = "unknown";
		}
		void printName()
		{
			cout << name << endl;
		}
};

int main()
{
	Student a( "xyz" );
	Student b;
	a.printName();
	b.printName();
	return 0;
}
