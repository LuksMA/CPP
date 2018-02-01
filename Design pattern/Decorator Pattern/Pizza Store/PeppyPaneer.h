#ifndef PEPPYPANEER_H
#define PEPPYPANEER_H

#include "Pizza.h"

class PeppyPaneer : public Pizza
{
    public:
        PeppyPaneer(){};
        virtual ~PeppyPaneer();
        int getCost() {  return 100; }
        string getDescription(){ return "PeppyPaneer"; };
};

#endif // PEPPYPANEER_H
