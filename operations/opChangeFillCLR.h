#pragma once
#include "operation.h"
class opChangeFillCLR :
    public operation
{
public:
    opChangeFillCLR(controller* pCont);

    virtual void Execute();
};

