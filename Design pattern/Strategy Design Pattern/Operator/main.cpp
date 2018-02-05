#include "Context.h"
#include "Strategy.h"
#include "OperationAdd.h"
#include "OperationSubstract.h"
#include "OperationMultiply.h"
#include <iostream>

using namespace std;

int main()
{
    Context* context = new Context(new OperationAdd());
    cout<<"10 + 5 = " << context->executeStrategy(10, 5)<<endl;

    context = new Context(new OperationSubstract());
    cout<<"10 - 5 = " << context->executeStrategy(10, 5)<<endl;

    context = new Context(new OperationMultiply());
    cout<<"10 * 5 = " << context->executeStrategy(10, 5)<<endl;
}
//10 + 5 = 15
//10 - 5 = 5
//10 * 5 = 50
