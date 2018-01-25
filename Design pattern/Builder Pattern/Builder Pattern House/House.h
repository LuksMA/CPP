#ifndef HOUSE_H
#define HOUSE_H

#include "HousePlan.h"

class House
{
    private:
        string basement;
        string structure;
        string roof;
        string interior;

    public:
        House();
        ~House();

        void setBasement(string b);
        void setStructur(string s);
        void setRoof(string r);
        void setInterior(string i);
};

#endif // HOUSE_H
