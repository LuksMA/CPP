#ifndef SIMPLEREMOTECONTROL_H
#define SIMPLEREMOTECONTROL_H

#include "Command.h"

class SimpleRemoteControl
{
    public:
        SimpleRemoteControl();
        void setCommand(Command* command);
        void buttonWasPressed();

    private:
        Command* slot;
};

#endif // SIMPLEREMOTECONTROL_H
