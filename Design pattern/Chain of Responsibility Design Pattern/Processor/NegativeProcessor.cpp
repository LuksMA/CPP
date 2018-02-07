#include "NegativeProcessor.h"

void NegativeProcessor :: setNext(Chain* c)
{
    nextInChain = c;
}
void NegativeProcessor :: process(Number* request)
{
    if (request->getNumber() < 0)
    {
        cout<<"NegativeProcessor : "<<request->getNumber()<<endl;
    }
    else
    {
        nextInChain->process(request);
    }
}
