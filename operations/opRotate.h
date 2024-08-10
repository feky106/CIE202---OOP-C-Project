#pragma once
#include "operation.h"
#include <fstream>
#include<iostream>
#include"operation.h"
#include"../Shapes/Shape.h"
#include"../controller.h"
#include "../Shapes/Graph.h"
class opRotate :
	public operation
{
private:
	double ratio = 1;

public:
	opRotate(controller* pcont);
	virtual ~opRotate();
	virtual void Execute();

};

