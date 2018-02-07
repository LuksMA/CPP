#ifndef NULLCOMMAND_H
#define NULLCOMMAND_H

#include "Command.h"
#include <iostream>

using namespace std;

class NullCommand : public Command
{
    public:
        void execute();
};

#endif // NULLCOMMAND_H
