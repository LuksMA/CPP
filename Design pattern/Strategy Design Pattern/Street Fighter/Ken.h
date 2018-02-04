#ifndef KEN_H
#define KEN_H

#include "Fighter.h"

class Ken : public Fighter
{
    public:
        Ken(KickBehavior* kickBehavior,JumpBehavior* jumpBehavior):Fighter(kickBehavior,jumpBehavior){};
        void display();
};

#endif // KEN_H
