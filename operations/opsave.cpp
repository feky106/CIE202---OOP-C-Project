#include "opsave.h"

void opsave::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("write file name , write cancel to cancel ");
	string name = pUI->GetSrting();
	if (name != "cancel") {
		ofstream savingfile(name); // shouldn't get string return a string to be used by the program ? why does it use printmessage function
		pControl->getGraph()->Save(savingfile); // how to call save all function 
		pUI->PrintMessage("saved");
	}
	else
	{
		pUI->PrintMessage("cancelled");
	}

};
