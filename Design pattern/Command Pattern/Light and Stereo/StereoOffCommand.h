#ifndef STEREOOFFCOMMAND_H
#define STEREOOFFCOMMAND_H

#include "Stereo.h"
#include "Command.h"

class StereoOffCommand : public Command
{
    public:
        StereoOffCommand(Stereo* stereo);
        void execute();

    private:
        Stereo* stereo;
};

#endif // STEREOOFFCOMMAND_H
