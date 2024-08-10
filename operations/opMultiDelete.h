#pragma once

#include"operation.h"

class opMultiDelete :public operation
{
public:
	opMultiDelete(controller* pCont);
	virtual void Execute();
};

