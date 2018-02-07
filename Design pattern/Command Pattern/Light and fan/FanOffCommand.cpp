#include "FanOffCommand.h"


void FanOffCommand::execute()
{
    mFan->off();
}
