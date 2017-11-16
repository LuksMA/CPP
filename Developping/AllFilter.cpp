#include "AllFilter.h"

void AllFilter :: addFilter()
{
    criterias.push_back(&A);
}

void AllFilter :: clearAllFilter(){
        criterias.clear();
}
