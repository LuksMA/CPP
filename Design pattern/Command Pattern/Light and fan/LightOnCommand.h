#ifndef LIGHTONCOMMAND_H
#define LIGHTONCOMMAND_H

#include "Command.h"
#include "Light.h"

class LightOnCommand : public Command
{
public:
    LightOnCommand(Light *light) : mLight(light) {};
    virtual ~LightOnCommand(){};
    void execute();


private:
    Light *mLight;
};

#endif // LIGHTONCOMMAND_H
