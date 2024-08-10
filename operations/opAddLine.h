#pragma once
#include "operation.h"
class opAddline :
	public operation
{
public:
	opAddline(controller* pCont);
	virtual ~opAddline();

	//Add line to the controller
	virtual void Execute();

};

