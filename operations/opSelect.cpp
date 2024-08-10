#include "opSelect.h"

#include "..\GUI\GUI.h"
#include "..\controller.h"
//Shapes
#include "..\shapes\Rect.h"
#include "..\shapes\RegPolygon.h"



opSelect::opSelect(controller* pCont) :operation(pCont)
{}
opSelect::~opSelect()
{}

//Execute the operation
void opSelect::Execute()
{
	Point P1;
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Click At The Figure You want to select/unselect");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	shape* sel = pGraph->Getshape(P1.x, P1.y);;


	if (sel) {

		if (pGraph->GetSelected()) {
			sel->SetSelected(true);
			pUI->ClearStatusBar();
			pUI->PrintMessage(sel->printforselection());
			pGraph->GetSelected()->SetSelected(false);
			pGraph->SetSelected(sel);

		}
		else {

			sel->SetSelected(true);
			pUI->ClearStatusBar(); //tring msg = "selecteed shape with width (" + to_string(sel->getborderwidth()) + ")";
			pUI->PrintMessage(sel->printforselection());

			pGraph->SetSelected(sel);
		}
	}
	else {
		string faildmsg = "NO SHPES IN";
		pUI->PrintMessage(faildmsg);
	}

}
