#include "MusicSystem.h"
#include <iostream>

using namespace std;

int main()
{
    MusicSystem obj;
    obj.playMusic();
    obj.nextSong();
    obj.stopMusic();
    obj.previousSong();
    obj.playMusic();
    return 0;
}

//
//Started Playing the music
//Playing the next song
//Stopped Playing the music
//Sorry previous song Cannot be played
//Started Playing the music
