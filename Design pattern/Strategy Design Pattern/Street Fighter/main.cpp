#include "JumpBehavior.h"
#include "ShortJump.h"
#include "LongJump.h"
#include "KickBehavior.h"
#include "TornadoKick.h"
#include "Fighter.h"
#include "Ken.h"

#include <iostream>

using namespace std;

int main()
{
    JumpBehavior* shortJump = new ShortJump();
    JumpBehavior* longJump = new LongJump();
    KickBehavior* tornadoKick = new TornadoKick();


    Fighter* ken = new Ken(tornadoKick,shortJump);
    ken->display();

    // Test behaviors
    ken->punch();
    ken->kick();
    ken->jump();

    // Change behavior dynamically (algorithms are interchangeable)
    ken->setJumpBehavior(longJump);
    ken->jump();
}
