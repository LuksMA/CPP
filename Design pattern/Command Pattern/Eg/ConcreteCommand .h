#ifndef CONCRETECOMMAND_H
#define CONCRETECOMMAND_H

#include "Command.h"
#include "Receiver.h"

class ConcreteCommand : public Command
{
    public:
        ConcreteCommand (Receiver * pReceiver);
        virtual ~ConcreteCommand ();
        virtual void execute();
    private:
        Receiver *m_pReceiver;
};

#endif // CONCRETECOMMAND _H
