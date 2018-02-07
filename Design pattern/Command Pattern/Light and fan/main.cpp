#include "Fan.h"
#include "Light.h"
#include "LightOnCommand.h"
#include "LightOffCommand.h"
#include "FanOnCommand.h"
#include "FanOffCommand.h"
#include "NullCommand.h"
#include "RemoteControl.h"

#include <iostream>

using namespace std;

int main()
{
    // Receiver
	Light *light = new Light;
	Fan *fan = new Fan;

	// concrete Command objects
	LightOnCommand *lightOn = new LightOnCommand(light);
	LightOffCommand *lightOff = new LightOffCommand(light);
	FanOnCommand *fanOn = new FanOnCommand(fan);
	FanOffCommand *fanOff = new FanOffCommand(fan);
	NullCommand *nullOn = new NullCommand();
	NullCommand *nullOff = new NullCommand();

	// invoker objects
	RemoteControl *control = new RemoteControl;

	// execute
	control->setCommand(LIGHT, lightOn, lightOff);
	control->onButtonPressed(LIGHT);
	control->offButtonPressed(LIGHT);

	control->setCommand(FAN, fanOn, fanOff);
	control->onButtonPressed(FAN);
	control->offButtonPressed(FAN);

	control->setCommand(NONE, nullOn, nullOff);
	control->onButtonPressed(NONE);

	delete light;
    delete lightOn;
    delete lightOff;
	delete fan;
	delete fanOn;
	delete fanOff;
	delete control;

	return 0;
}

//The light is on
//The light is off
//The fan is on
//The fan is off
//Null command: does nothing
