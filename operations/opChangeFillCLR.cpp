#include "opChangeFillCLR.h"
#include "../controller.h"
#include "../GUI\GUI.h"
#include"../Shapes/Graph.h"


opChangeFillCLR::opChangeFillCLR(controller* pCont) :operation(pCont)
{
}


void opChangeFillCLR::Execute()
{
	Point P;
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Changing fill CLR, changeing <SELECTED> or <FILL> ? --> ");
	string t = pUI->GetSrting();

	if (t == "SELECTED") {
		Graph* pGr = pControl->getGraph(); // getting a pointer of grapg so that i can call delete shape and getshape (but what does getshape do ??)

		pUI->ClearStatusBar();
		pUI->PrintMessage("Choose the CLR from the Drowing bar ...");
		pUI->GetPointClicked(P.x, P.y);

		if (P.x < 50 && P.y > 400)
		{
			int selected = (P.y - 400) / 50;

			if (selected == 0) {
				pUI->PrintMessage("COLOR IS RED");
				color CLR = color(255, 0, 0);
				pGr->changeFillCLR(CLR);

			}
			else if (selected == 1) {
				pUI->PrintMessage("COLOR IS GREEN");
				color CLR = color(0, 255, 0);
				pGr->changeFillCLR(CLR);
			}
			else if (selected == 2) {
				pUI->PrintMessage("COLOR IS YELLOW");
				color CLR = color(255, 255, 0);
				pGr->changeFillCLR(CLR);
			}
			else if (selected == 3) {
				pUI->PrintMessage("COLOR IS BLUE");
				color CLR = color(0, 0, 255);
				pGr->changeFillCLR(CLR);
			}
		}
		else {
			pUI->PrintMessage("NOT A COLOR");
		}

	}
	else if (t == "FILL") {
		pUI->ClearStatusBar();
		pUI->PrintMessage("Choose the CLR from the Drowing bar ...");
		pUI->GetPointClicked(P.x, P.y);

		if (P.x < 50 && P.y > 400)
		{
			int selected = (P.y - 400) / 50;

			if (selected == 0) {
				pUI->PrintMessage("COLOR IS RED");
				color CLR = color(255, 0, 0);
				pUI->ChangeFillCLR(CLR);

			}
			else if (selected == 1) {
				pUI->PrintMessage("COLOR IS GREEN");
				color CLR = color(0, 255, 0);
				pUI->ChangeFillCLR(CLR);
			}
			else if (selected == 2) {
				pUI->PrintMessage("COLOR IS YELLOW");
				color CLR = color(255, 255, 0);
				pUI->ChangeFillCLR(CLR);
			}
			else if (selected == 3) {
				pUI->PrintMessage("COLOR IS BLUE");
				color CLR = color(0, 0, 255);
				pUI->ChangeFillCLR(CLR);
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