#include "LightOffCommand.h"

void LightOffCommand :: execute()
{
    mLight->off();
}
