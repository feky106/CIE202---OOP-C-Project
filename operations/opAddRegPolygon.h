#pragma once
#include "operation.h"
class opAddRegPolygon :
	public operation
{
public:
	opAddRegPolygon(controller* pCont);
	virtual ~opAddRegPolygon();

	//Add Regular Polygon to the controller
	virtual void Execute();
};

