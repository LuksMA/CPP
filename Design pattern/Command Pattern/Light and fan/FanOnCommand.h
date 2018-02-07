#ifndef FANONCOMMAND_H
#define FANONCOMMAND_H

#include "Fan.h"
#include "Command.h"

class FanOnCommand : public Command
{
    public:
        FanOnCommand(Fan *fan) : mFan(fan) {};
        virtual ~FanOnCommand(){};
        void execute();

    private:
        Fan *mFan;
};

#endif // FANONCOMMAND_H
