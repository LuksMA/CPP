#include "RemoteControl.h"

RemoteControl::RemoteControl(): mOnCommand(MaxCommand), mOffCommand(MaxCommand)
{
    Command *nullCmd = new NullCommand;
    for(int i = 0; i < MaxCommand; i++)
    {
        mOffCommand[i] = nullCmd;
        mOnCommand[i] = nullCmd;
    }
}


void RemoteControl::setCommand(Receiver id, Command *onCmd, Command *offCmd)
{
    mOnCommand[id] = onCmd;
    mOffCommand[id] = offCmd;
}

void RemoteControl::onButtonPressed(Receiver id)
{
    mOnCommand[id]->execute();
}

void RemoteControl::offButtonPressed(Receiver id)
{
    mOffCommand[id]->execute();
}
