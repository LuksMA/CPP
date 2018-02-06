#ifndef PLAYINGSTATE_H
#define PLAYINGSTATE_H

#include "MusicSystem.h"

class PlayingState : public State
{
    public:
        bool stopMusic(MusicSystem * pMusicSys);
        bool previousSong(MusicSystem * pMusicSys);
        bool nextSong(MusicSystem * pMusicSys);
};

#endif // PLAYINGSTATE_H
