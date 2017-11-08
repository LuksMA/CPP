/// We can also call private function of derived class from a base class pointer by declaring that function in the base class as virtual.
#include <iostream>

using namespace std;

class Animals
{
	public:
		virtual void sound()
		{
			cout << "This is parent class" << endl;
		}
};

class Dogs : public Animals
{
	private:
		virtual void sound()
		{
			cout << "Dogs bark" << endl;
		}
};

int main()
{
	Animals *a;
	Dogs b;
	a = &b;
	a->sound();
	return 0;
}
