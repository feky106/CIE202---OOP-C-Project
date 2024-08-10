#pragma once
#include"operation.h"
#include<iostream>
#include<fstream>
#include"../Shapes/Shape.h"
#include"../controller.h"
class opload : public operation
{
public:
	opload(controller* pCont) : operation(pCont) {};
	void Execute() {
		GUI* pUI = pControl->GetUI();
		pUI->PrintMessage("write file name.txt , wrirte cancel to cancel ");
		string name = pUI->GetSrting();
		if (name != "cancel") {
			ifstream loadingfile(name);
			pControl->getGraph()->load(loadingfile);
			pUI->PrintMessage("loaded");
		}
		else
		{
			pUI->PrintMessage("cancelled");

		}

	}

};

