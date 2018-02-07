#include "ZeroProcessor.h"


void ZeroProcessor :: setNext(Chain* c)
{
    nextInChain = c;
}
void ZeroProcessor :: process(Number* request)
{
    if (request->getNumber() == 0)
    {
        cout<<"ZeroProcessor : "<<request->getNumber()<<endl;
    }
    else
    {
        nextInChain->process(request);
    }
}
