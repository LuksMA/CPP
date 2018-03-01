#ifndef REDCIRCLE_H
#define REDCIRCLE_H

#include "DrawAPI.h"


class RedCircle : public DrawAPI
{
    public:
        RedCircle();
        virtual ~RedCircle();

        void drawCircle(int radius, int x, int y);
};

#endif // REDCIRCLE_H
