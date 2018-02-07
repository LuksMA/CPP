#ifndef COMMAND_H
#define COMMAND_H

enum Receiver
{
	LIGHT = 0, FAN, DOOR, OVEN, NONE
};

class Command
{
    public:
        virtual void execute() = 0;
};

#endif // COMMAND_H
