#include "opMultiDelete.h"
#include "../controller.h"
#include<windows.h>  
#include<iostream>



opMultiDelete::opMultiDelete(controller* pCont) : operation(pCont) {};

void opMultiDelete::Execute()
{
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Multi Del>>");

	pGraph->multidelete();

	/*
	for (int i = 0; i < n; i++) {
		pUI->GetPointClicked(arrx[i], arry[i]);
	}
	pControl->getGraph()->multiselect(arrx, arry, n);
	pControl->UpdateInterface();
	pUI->PrintMessage("the selcted shapes are highlighted ");
	Sleep(3000);
	pControl->getGraph()->multidelete();
	pUI->PrintMessage("shapes deleted succefully ");
	//pControl->getGraph()->clearmultiselectedvector();

*/
}