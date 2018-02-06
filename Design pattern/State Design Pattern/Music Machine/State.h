#ifndef STATE_H
#define STATE_H

#include "MusicSystem.h"
#include <iostream>

using namespace std;

class MusicSystem;

class State {
public:
    virtual bool playMusic(MusicSystem * pMusicSys);
    virtual bool stopMusic(MusicSystem * pMusicSys);
    virtual bool previousSong(MusicSystem * pMusicSys);
    virtual bool nextSong(MusicSystem * pMusicSys);
};




#endif // STATE_H
