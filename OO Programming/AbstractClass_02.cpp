#include <iostream>

using namespace std;

class Animals
{
	public:
		virtual void sound() = 0;
};

class Dogs
{
	public:
		void sound()
		{
			cout << "Dogs bark" << endl;
		}
};

class Cats
{
	public:
		void sound()
		{
			cout << "Cats meow" << endl;
		}
};

class Pigs
{
	public:
		void sound()
		{
			cout << "Pigs snort" << endl;
		}
};

int main()
{
	Dogs d;
	Cats c;
	Pigs p;
	d.sound();
	c.sound();
	p.sound();
	return 0;
}
