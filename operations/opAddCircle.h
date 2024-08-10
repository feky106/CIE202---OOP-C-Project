#pragma once
#include "../operations/operation.h"
class opAddCircle :
	public operation
{
public:
	opAddCircle(controller* pCont);
	virtual ~opAddCircle();

	//Add Circle to the controller
	virtual void Execute();
};

