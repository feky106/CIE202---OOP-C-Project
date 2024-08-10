#pragma once
#include "operation.h"
class opZoomIn : public operation
{
public:
	opZoomIn(controller* pCont);
	virtual ~opZoomIn();

	//Add zoom to the controller
	virtual void Execute();

};