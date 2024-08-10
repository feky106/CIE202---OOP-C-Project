#pragma once
#include "operation.h"
class opChangeLineCLR :
    public operation
{
public:
    opChangeLineCLR(controller* pCont);

    virtual void Execute();
};

