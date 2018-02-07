#ifndef LIGHTOFFCOMMAND_H
#define LIGHTOFFCOMMAND_H

#include "Command.h"
#include "Light.h"

class LightOffCommand : public Command
{
public:
    LightOffCommand(Light *light) : mLight(light) {};
    virtual ~LightOffCommand(){};
    void execute();


private:
    Light *mLight;
};

#endif // LIGHTOFFCOMMAND_H
