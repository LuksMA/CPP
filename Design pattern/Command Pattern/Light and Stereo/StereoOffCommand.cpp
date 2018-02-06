#include "StereoOffCommand.h"

StereoOffCommand::StereoOffCommand(Stereo* stereo)
{
    this->stereo = stereo;
}
void StereoOffCommand::execute(){
    stereo->off();
}
