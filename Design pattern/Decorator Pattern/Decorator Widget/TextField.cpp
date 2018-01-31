#include "TextField.h"

TextField::TextField(int w, int h)
{
    width = w;
    height = h;
}

void TextField::draw()
{
    cout << "TextField: " << width << ", " << height << '\n';
}
