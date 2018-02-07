#ifndef REMOTECONTROL_H
#define REMOTECONTROL_H

#include "Command.h"
#include "NullCommand.h"
#include <vector>

using namespace std;

const int MaxCommand = 5;

class RemoteControl
{
    public:
        RemoteControl();
        void setCommand(Receiver id, Command *onCmd, Command *offCmd);
        void onButtonPressed(Receiver id);
        void offButtonPressed(Receiver id);

    private:
        vector<Command*> mOnCommand, mOffCommand;
};

#endif // REMOTECONTROL_H
