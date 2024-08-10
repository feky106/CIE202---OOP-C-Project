#pragma once

#include "operation.h"

//Add select operation class
class opMultiSelect : public operation
{
public:
	opMultiSelect(controller* pCont);
	virtual ~opMultiSelect();

	//Add select to the controller
	virtual void Execute();

};