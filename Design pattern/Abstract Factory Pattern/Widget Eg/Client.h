#ifndef CLIENT_H
#define CLIENT_H

#include "Factory.h"
#include "Widget.h"

class Client
{
    public:
        Client(Factory *f);
        virtual ~Client();
        void draw();
        void display_window_one();
        void display_window_two();

    private:
        Factory *factory;
};

#endif // CLIENT_H
