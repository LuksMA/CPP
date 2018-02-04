#include "Fighter.h"

Fighter::Fighter(KickBehavior* kickBehavior, JumpBehavior* jumpBehavior)
{
    this->jumpBehavior = jumpBehavior;
    this->kickBehavior = kickBehavior;
}

void Fighter::punch(){
    cout<<"Default Punch"<<endl;
}

void Fighter::kick(){
    kickBehavior->kick();
}

void Fighter::jump(){
    jumpBehavior->jump();
}

void Fighter::roll(){
    cout<<"Default Roll"<<endl;
}


void Fighter::setKickBehavior(KickBehavior* kickBehavior){
    this->kickBehavior = kickBehavior;
}

void Fighter::setJumpBehavior(JumpBehavior* jumpBehavior){
    this->jumpBehavior = jumpBehavior;
}

