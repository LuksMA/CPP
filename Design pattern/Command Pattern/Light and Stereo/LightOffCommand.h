#ifndef LIGHTOFFCOMMAND_H
#define LIGHTOFFCOMMAND_H

#include "Light.h"
#include "Command.h"

class LightOffCommand : public Command
{
    public:
        LightOffCommand(Light* light);
        void execute();

    private:
        Light* light;
};

#endif // LIGHTOFFCOMMAND_H
