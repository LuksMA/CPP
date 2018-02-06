#ifndef STEREOONWITHCDCOMMAND_H
#define STEREOONWITHCDCOMMAND_H

#include "Stereo.h"
#include "Command.h"

class StereoOnWithCDCommand : public Command
{
    public:
        StereoOnWithCDCommand(Stereo* stereo);
        void execute();

    private:
        Stereo* stereo;
};

#endif // STEREOONWITHCDCOMMAND_H
