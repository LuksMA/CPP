#ifndef HOUSEPLAN_H
#define HOUSEPLAN_H

#include <string>
using namespace std;

class HousePlan
{
    public:
        HousePlan();
        ~HousePlan();

        virtual void setBasement(string basement) = 0;
        virtual void setStructure(string structure) = 0;
        virtual void setRoof(string roof) = 0;
        virtual void setInterior(string interior) = 0;
};

#endif // HOUSEPLAN_H
