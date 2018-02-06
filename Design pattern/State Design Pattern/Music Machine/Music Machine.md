base on http://thispointer.com/state-design-pattern/    

If music system is in **STOPPED** states then,
* STOP, NEXT and PREV request will have no effect
* PLAY Request will play the music and will also change the current State of Music System to PLAYING.

If music system is in **PLAYING** states then,
* PLAY request will have no effect
* STOP Request will stop the music and will also change the current State of Music System to STOPPED.
* PREV Request will play the previous song.
* NEXT Request will play the previous song.
