#pragma once
#include <fstream>
#include<iostream>
#include"operation.h"
#include"../Shapes/Shape.h"
#include"../controller.h"
#include "../Shapes/Graph.h"


class opResize : public operation {
private:
	double ratio = 1;

public:
	opResize(controller* pcont);
	virtual ~opResize();
	virtual void Execute();

};