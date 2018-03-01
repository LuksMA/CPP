#ifndef GREENCIRCLE_H
#define GREENCIRCLE_H

#include "DrawAPI.h"


class GreenCircle : public DrawAPI
{
    public:
        GreenCircle();
        virtual ~GreenCircle();

        void drawCircle(int radius, int x, int y);
};

#endif // GREENCIRCLE_H
