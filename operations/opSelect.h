#pragma once

#include "operation.h"

//Add select operation class
class opSelect : public operation
{
public:
	opSelect(controller* pCont);
	virtual ~opSelect();

	//Add select to the controller
	virtual void Execute();

};

