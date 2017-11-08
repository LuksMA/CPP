/// Protected
/// In the 'Student' class, we made name protected. So, it can be accessed directly within its subclass 'Undergraduate'.
#include <iostream>
#include <string>

using namespace std;

class Student		//base class
{
	protected:
		string name;
	public:
		void setName( string n )
		{
			name = n;
		}
};

class Undergraduate : public Student	//derived class
{
	public:
		void printName()
		{
			cout << name << endl;
		}
};

int main()
{	Undergraduate u;
	u.setName("xyz");
	u.printName();
	return 0;
}
