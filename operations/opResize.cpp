#include "../operations/opResize.h"

opResize::opResize(controller* pcont) :operation(pcont) {}
opResize :: ~opResize() {}
void opResize::Execute() {
	GUI* pUI = pControl->GetUI(); // getting a pointer from gui so that i can call print message and call selectshape
	pUI->PrintMessage("enter ratio -> 0.25 or 0.5 or 2 or 4");
	ratio = stod(pUI->GetSrting());
	while (ratio != 0.25 && ratio != 0.5 && ratio != 2 && ratio != 4) {
		pUI->PrintMessage("error, enter ratio -> 0.25 or 0.5 or 2 or 4");
		ratio = stod(pUI->GetSrting());
	}
	Graph* pGr = pControl->getGraph(); // getting a pointer of grapg so that i can call delete shape and getshape (but what does getshape do ??)
	pGr->Resize(pGr->GetSelected(), ratio); // is done after making select function 
	pUI->PrintMessage("change size");

}
