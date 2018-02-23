#include "RefinedAbstraction.h"

RefinedAbstraction::RefinedAbstraction()
{
    //ctor
}

RefinedAbstraction::RefinedAbstraction(Implementor* imp)
    :Abstraction(imp)
{
}

RefinedAbstraction::~RefinedAbstraction()
{
    //dtor
}

void RefinedAbstraction::operation()
{
    cout << "do something else ,and then " << endl;
    m_pImp->operationImp();
}
