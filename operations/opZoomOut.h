#pragma once
#include "operation.h"
class opZoomOut : public operation
{
public:
	opZoomOut(controller* pCont);
	virtual ~opZoomOut();

	//Add zoom to the controller
	virtual void Execute();

};