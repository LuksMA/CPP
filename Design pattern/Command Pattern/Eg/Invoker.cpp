#include "Invoker.h"

Invoker::Invoker(Command * pCommand){
	m_pCommand = pCommand;
}

Invoker::~Invoker()
{
    //dtor
}

void Invoker::call(){
	cout << "invoker calling" << endl;
	m_pCommand->execute();
}
