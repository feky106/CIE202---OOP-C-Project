#pragma once
#include"operation.h"
class opdeleteshape : public operation
{
public:
	opdeleteshape(controller* pcont);
	virtual void Execute();


};