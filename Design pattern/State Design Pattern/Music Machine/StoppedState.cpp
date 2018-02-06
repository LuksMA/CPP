#include "StoppedState.h"
#include "PlayingState.h"

bool StoppedState::playMusic(MusicSystem * pMusicSys) {
    pMusicSys->setCurrentState(new PlayingState());
    std::cout << "Started Playing the music\n";
    return true;
}
