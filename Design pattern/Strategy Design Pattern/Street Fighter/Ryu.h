#ifndef RYU_H
#define RYU_H

#include "Fighter.h"

class Ryu : public Fighter
{
    public:
        Ryu(KickBehavior* kickBehavior,JumpBehavior* jumpBehavior):Fighter(kickBehavior,jumpBehavior){};
        void display();
};

#endif // RYU_H
