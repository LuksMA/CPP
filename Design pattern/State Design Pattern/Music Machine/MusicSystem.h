#ifndef MUSICSYSTEM_H
#define MUSICSYSTEM_H

#include "State.h"

class State;

class MusicSystem {

public:
    MusicSystem();
    bool playMusic();
    bool stopMusic();
    bool previousSong();
    bool nextSong();
    void setCurrentState(State* currentState);
private:
    friend class State;
    State* m_CurrentState;
};

#endif // MUSICSYSTEM_H
