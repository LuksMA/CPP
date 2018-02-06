base on http://thispointer.com/state-design-pattern/    

If music system is in **STOPPED** states then,
* But pressing any other button except PLAY like STOP, NEXT and PREV will have no effect.
* Pressing the PLAY button will play the music and will move the system in PLAYING state.

If music system is in **PLAYING** states then,
* Pressing stop button will stop the music and move the music system to STOPPED state.
* Pressing next button will play the next song.
* Pressing prev button will play the previous song.
