#include "opMultiSelect.h"
#include "..\shapes\Rect.h"
#include "..\shapes\RegPolygon.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"

opMultiSelect::opMultiSelect(controller* pCont) :operation(pCont)
{}
opMultiSelect::~opMultiSelect()
{}

//Execute the operation
void opMultiSelect::Execute()
{
	Point P1;
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Multi_Select, Click At The Figures You want to select/unselect");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	shape* msel = pGraph->Getshape(P1.x, P1.y);



	if (msel) {
		if (pGraph->CheckSelect(msel)) {
			msel->SetSelected(false);
			pUI->ClearStatusBar();
			pGraph->SelectList(msel, false);
			pUI->PrintMessage("Unselecting ths Shape ... ");
		}
		else {
			pUI->PrintMessage("Selecting ths Shape ... ");

			msel->SetSelected(true);
			pUI->ClearStatusBar();
			pUI->PrintMessage(msel->printforselection());
			pGraph->SelectList(msel, true);
		}
	}
	else {
		string faildmsg = "NO SHPES IN";
		pUI->PrintMessage(faildmsg);
	}

}
