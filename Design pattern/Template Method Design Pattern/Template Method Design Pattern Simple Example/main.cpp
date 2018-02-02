#include "Base.h"
#include "One.h"
#include "Two.h"
#include <iostream>

using namespace std;

int main()
{
    Base *array[] = {new One(), new Two()};
    array[0]->execute();cout<<endl;
    array[1]->execute();cout<<endl;
}

//a b c d e
//a 2 c 4 e
