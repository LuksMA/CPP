#include <iostream>
#include "ConcreteMediator.h"
#include "ConcreteColleagueA.h"
#include "ConcreteColleagueB.h"

using namespace std;

int main()
{
	ConcreteColleagueA * pa = new ConcreteColleagueA();
	ConcreteColleagueB * pb = new ConcreteColleagueB();
	ConcreteMediator * pm = new ConcreteMediator();
	pm->registered(1,pa);
	pm->registered(2,pb);

	// sendmsg from a to b
	pa->sendmsg(2,"hello,i am a");
	// sendmsg from b to a
	pb->sendmsg(1,"hello,i am b");

	delete pa;
	delete pb;
	delete pm;
	return 0;
}

//send msg from colleagueA,to:2
//ConcreteColleagueB reveivemsg:hello,i am a
//send msg from colleagueB,to:1
//ConcreteColleagueA reveivemsg:hello,i am b
