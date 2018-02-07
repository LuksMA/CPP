#ifndef FANOFFCOMMAND_H
#define FANOFFCOMMAND_H

#include "Fan.h"
#include "Command.h"

class FanOffCommand : public Command
{
    public:
        FanOffCommand(Fan *fan) : mFan(fan) {};
        virtual ~FanOffCommand(){};
        void execute();

    private:
        Fan *mFan;
};

#endif // FANOFFCOMMAND_H
