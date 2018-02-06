#include "PlayingState.h"
#include "StoppedState.h"

bool PlayingState::stopMusic(MusicSystem * pMusicSys)
{
    pMusicSys->setCurrentState(new StoppedState());
    std::cout << "Stopped Playing the music\n";
    return true;
}
bool PlayingState::previousSong(MusicSystem * pMusicSys)
{
    std::cout << "Playing the previous song\n";
    return true;
}
bool PlayingState::nextSong(MusicSystem * pMusicSys)
{
    std::cout << "Playing the next song\n";
    return true;
}
