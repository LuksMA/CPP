#include "PositiveProcessor.h"

void PositiveProcessor :: setNext(Chain* c)
{
    nextInChain = c;
}
void PositiveProcessor :: process(Number* request)
{
    if (request->getNumber() > 0)
    {
        cout<<"PositiveProcessor : "<<request->getNumber()<<endl;
    }
    else
    {
        nextInChain->process(request);
    }
}
