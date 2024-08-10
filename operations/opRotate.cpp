#include "opRotate.h"
opRotate::opRotate(controller* pcont) :operation(pcont) {}
opRotate :: ~opRotate() {}
void opRotate::Execute() {
	GUI* pUI = pControl->GetUI(); // getting a pointer from gui so that i can call print message and call selectshape
	Graph* pGr = pControl->getGraph(); // getting a pointer of grapg so that i can call delete shape and getshape (but what does getshape do ??)
	pGr->Rotate(pGr->GetSelected()); // is done after making select function 
	pUI->PrintMessage("Rotate by 90 degrees");
}