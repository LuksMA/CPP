#ifndef FIGHTER_H
#define FIGHTER_H

#include "JumpBehavior.h"
#include "KickBehavior.h"


class Fighter
{
    public:
        Fighter(KickBehavior* kickBehavior, JumpBehavior* jumpBehavior);
        void punch();
        void kick();
        void jump();
        void roll();
        void setKickBehavior(KickBehavior* kickBehavior);
        void setJumpBehavior(JumpBehavior* jumpBehavior);
        virtual void display() = 0;

    private:
        KickBehavior* kickBehavior;
        JumpBehavior* jumpBehavior;
};

#endif // FIGHTER_H
