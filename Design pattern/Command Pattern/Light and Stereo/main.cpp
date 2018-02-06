#include "SimpleRemoteControl.h"
#include "Light.h"
#include "Stereo.h"
#include "LightOnCommand.h"
#include "LightOffCommand.h"
#include "StereoOnWithCDCommand.h"
#include "StereoOffCommand.h"

#include <iostream>

using namespace std;

int main()
{
    SimpleRemoteControl* remote = new SimpleRemoteControl();
    Light* light = new Light();
    Stereo* stereo = new Stereo();

    cout<<"Set remote with Light. "<<endl;
    remote->setCommand(new LightOnCommand(light));
    remote->buttonWasPressed();
    remote->setCommand(new LightOffCommand(light));
    remote->buttonWasPressed();

    cout<<"\nSet remote with Stereo. "<<endl;
    remote->setCommand(new StereoOnWithCDCommand(stereo));
    remote->buttonWasPressed();
    remote->setCommand(new StereoOffCommand(stereo));
    remote->buttonWasPressed();
}


//Set remote with Light.
//Light is on.
//Light is off.
//
//Set remote with Stereo.
//Stereo is on
//Stereo is set for CD input
//Stereo volume set 11
//Stereo is off
