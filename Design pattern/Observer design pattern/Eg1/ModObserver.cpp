#include "ModObserver.h"


ModObserver::ModObserver(Subject *model, int mod)
{
    model->attach(this);
    m_mod = mod;
}
void ModObserver::update(int v)
{
    cout << v << " mod " << m_mod << " is " << v % m_mod << '\n';
}
