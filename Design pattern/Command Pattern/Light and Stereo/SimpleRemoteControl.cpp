#include "SimpleRemoteControl.h"

SimpleRemoteControl::SimpleRemoteControl()
{
    //ctor
}
void SimpleRemoteControl::setCommand(Command* command)
{
    // set the command the remote will
    // execute
    slot = command;
}
void SimpleRemoteControl::buttonWasPressed(){
    slot->execute();
}
