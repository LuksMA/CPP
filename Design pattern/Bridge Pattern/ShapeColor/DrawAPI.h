#ifndef DRAWAPI_H
#define DRAWAPI_H

#include <iostream>

using namespace std;

class DrawAPI
{
    public:
        DrawAPI();
        virtual ~DrawAPI();
        virtual void drawCircle(int radius, int x, int y) = 0;
};

#endif // DRAWAPI_H
