#include "Chain.h"
#include "NegativeProcessor.h"
#include "ZeroProcessor.h"
#include "PositiveProcessor.h"


int main()
{
    Chain* c1 = new NegativeProcessor();
    Chain* c2 = new ZeroProcessor();
    Chain* c3 = new PositiveProcessor();
    c1->setNext(c2);
    c2->setNext(c3);

    //calling chain of responsibility
    c1->process(new Number(90));
    c1->process(new Number(-50));
    c1->process(new Number(0));
    c1->process(new Number(91));
    return 0;
}

//PositiveProcessor : 90
//NegativeProcessor : -50
//ZeroProcessor : 0
//PositiveProcessor : 91
