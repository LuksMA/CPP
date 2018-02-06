#ifndef LIGHTONCOMMAND_H
#define LIGHTONCOMMAND_H

#include "Light.h"
#include "Command.h"

class LightOnCommand : public Command
{
    public:
        LightOnCommand(Light* light);
        void execute();

    private:
        Light* light;
};

#endif // LIGHTONCOMMAND_H
