#include "Client.h"

Client::Client(Factory *f)
{
    factory = f;
}

Client::~Client()
{
    //dtor
}

void Client::draw()
{
    Widget *w = factory->create_button();
    w->draw();
    display_window_one();
    display_window_two();
}

void Client::display_window_one()
{
    Widget *w[] =
    {
        factory->create_button(),
        factory->create_menu()
    };
    w[0]->draw();
    w[1]->draw();
}

void Client::display_window_two()
{
    Widget *w[] =
    {
        factory->create_menu(),
        factory->create_button()
    };
    w[0]->draw();
    w[1]->draw();
}
