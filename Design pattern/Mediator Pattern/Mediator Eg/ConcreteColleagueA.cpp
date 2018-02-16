#include "ConcreteColleagueA.h"


ConcreteColleagueA::ConcreteColleagueA()
{
    //ctor
}

ConcreteColleagueA::~ConcreteColleagueA()
{
    //dtor
}

void ConcreteColleagueA::sendmsg(int toWho,string str){
	cout << "send msg from colleagueA,to:" << toWho << endl;
	m_pMediator->operation(toWho,str);
}

void ConcreteColleagueA::receivemsg(string str){
	cout << "ConcreteColleagueA reveivemsg:" << str <<endl;
}
