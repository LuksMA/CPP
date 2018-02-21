#ifndef TABLEFAN_H
#define TABLEFAN_H

#include "IFan.h"
class TableFan : public IFan
{
    public:
        TableFan();
        virtual ~TableFan();
        void SwitchOn();
        void SwitchOff();
};

#endif // TABLEFAN_H
