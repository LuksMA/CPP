#include "StereoOnWithCDCommand.h"

StereoOnWithCDCommand::StereoOnWithCDCommand(Stereo* stereo)
{
    this->stereo = stereo;
}
void StereoOnWithCDCommand::execute(){
         stereo->on();
         stereo->setCD();
         stereo->setVolume(11);
     }
