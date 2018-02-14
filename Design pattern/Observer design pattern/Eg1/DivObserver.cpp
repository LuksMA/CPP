#include "DivObserver.h"

DivObserver::DivObserver(Subject *model, int div)
{
    model->attach(this);
    m_div = div;
}
void DivObserver::update(int v)
{
    cout << v << " div " << m_div << " is " << v / m_div << '\n';
}
