#pragma once
#include "operation.h"
class opAddsquare :
	public operation
{
public:
	opAddsquare(controller* pCont);
	virtual ~opAddsquare();

	//Add square to the controller
	virtual void Execute();

};


