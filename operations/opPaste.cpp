#include "opPaste.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"


#include "..\shapes\Rect.h"
#include "..\Shapes\line.h"
#include "..\shapes\RegPolygon.h"
#include "..\Shapes\triangle.h"

opPaste::opPaste(controller* pCont) : operation(pCont) {}


void opPaste::Execute()
{
    Point ref;

    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();

    pUI->PrintMessage("Paste Shape: Click on a ref. point");
    pUI->GetPointClicked(ref.x, ref.y);

    pUI->ClearStatusBar();

    pGr->paste(ref);
}
