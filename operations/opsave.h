#pragma once
#include <fstream>
#include<iostream>
#include"operation.h"
#include"../Shapes/Shape.h"
#include"../controller.h"
#include "../Shapes/Graph.h"

class opsave : public operation
{
public:
	opsave(controller* pcont) :operation(pcont) {}
	~opsave() {}
	virtual void Execute();

};

