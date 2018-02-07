#include "FanOnCommand.h"


void FanOnCommand::execute()
{
    mFan->on();
}
