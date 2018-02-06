#ifndef STOPPEDSTATE_H
#define STOPPEDSTATE_H

//#include "State.h"
#include "MusicSystem.h"

class StoppedState : public State
{
    public:
        bool playMusic(MusicSystem * pMusicSys);

};

#endif // STOPPEDSTATE_H
