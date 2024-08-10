#include "opChangeLineCLR.h"
#include "../controller.h"
#include "../GUI\GUI.h"

opChangeLineCLR::opChangeLineCLR(controller* pCont) :operation(pCont)
{
}

void opChangeLineCLR::Execute()
{
	Graph* pGr = pControl->getGraph(); // getting a pointer of grapg so that i can call delete shape and getshape (but what does getshape do ??)
	
	Point P;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Changing drowing CLR, changeing <SELECTED> or <PEN> ? --> ");
	string t = pUI->GetSrting();

	if (t == "SELECTED") {
		pUI->ClearStatusBar();
		pUI->PrintMessage("Choose the CLR from the Drowing bar ...");
		pUI->GetPointClicked(P.x, P.y);

		if (P.x < 50 && P.y > 400)
		{
			int selected = (P.y - 400) / 50;
			
			if (selected == 0) {
				pUI->PrintMessage("COLOR IS RED");
				color CLR = color(255, 0, 0);
				pGr->changeDrowCLR(CLR);
			}
			else if (selected == 1) {
				pUI->PrintMessage("COLOR IS GREEN");
				color CLR = color(0, 255, 0);
				pGr->changeDrowCLR(CLR);
			}
			else if (selected == 2) {
				pUI->PrintMessage("COLOR IS YELLOW");
				color CLR = color(255, 255, 0);
				pGr->changeDrowCLR(CLR);
			}
			else if (selected == 3) {
				pUI->PrintMessage("COLOR IS BLUE");
				color CLR = color(0, 0, 255);
				pGr->changeDrowCLR(CLR);
			}
		}
		else {
			pUI->PrintMessage("NOT A COLOR");
		}

	}
	else if (t == "PEN") {
		pUI->ClearStatusBar();
		pUI->PrintMessage("Choose the CLR from the Drowing bar ...");
		pUI->GetPointClicked(P.x, P.y);

		if (P.x < 50 && P.y > 400)
		{
			int selected = (P.y - 400) / 50;

			if (selected == 0) {
				pUI->PrintMessage("COLOR IS RED");
				color CLR = color(255, 0, 0);
				pUI->ChangeDrowCLR(CLR);

			}
			else if (selected == 1) {
				pUI->PrintMessage("COLOR IS GREEN");
				color CLR = color(0, 255, 0);
				pUI->ChangeDrowCLR(CLR);
			}
			else if (selected == 2) {
				pUI->PrintMessage("COLOR IS YELLOW");
				color CLR = color(255, 255, 0);
				pUI->ChangeDrowCLR(CLR);
			}
			else if (selected == 3) {
				pUI->PrintMessage("COLOR IS BLUE");
				color CLR = color(0, 0, 255);
				pUI->ChangeDrowCLR(CLR);
			}
		}
		else {
			pUI->PrintMessage("NOT A COLOR");
		}


	}
	else {
		pUI->PrintMessage("WRONG COMMAND");
	}
}

