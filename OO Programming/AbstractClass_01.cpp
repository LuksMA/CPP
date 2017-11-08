/// An abstract class is a class whose instances (objects) can't be made.
/// An abstract class has at least one abstract function (pure virtual function).
#include <iostream>

using namespace std;

class Employee                    //  abstract base class
{
	virtual int getSalary() = 0;    // pure virtual function
};

class Developer : public Employee
{
	int salary;
	public:
		Developer(int s)
		{
			salary = s;
		}
		int getSalary()
		{
			return salary;
		}
};

class Driver : public Employee
{
	int salary;
	public:
		Driver(int t)
		{
			salary = t;
		}
		int getSalary()
		{
			return salary;
		}
};

int main()
{
	Developer d1(5000);
	Driver d2(3000);
	int a, b;
	a = d1.getSalary();
	b = d2.getSalary();
	cout << "Salary of Developer : " << a << endl;
	cout << "Salary of Driver : " << b << endl;
	return 0;
}
