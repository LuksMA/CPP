#ifndef CHUNLI_H
#define CHUNLI_H

#include "Fighter.h"
class ChunLi : public Fighter
{
    public:
        ChunLi(KickBehavior* kickBehavior,JumpBehavior* jumpBehavior):Fighter(kickBehavior,jumpBehavior){};
        void display();
};

#endif // CHUNLI_H
