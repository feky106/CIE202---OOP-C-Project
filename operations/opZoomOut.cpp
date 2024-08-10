#include "opZoomOut.h"
#include "..\controller.h"

#include "..\GUI\GUI.h"
#include "..\shapes\Rect.h"
#include "..\shapes\RegPolygon.h"
#include "..\controller.h"
#include"../Shapes/Graph.h"
opZoomOut::opZoomOut(controller* pCont) :operation(pCont)
{}
opZoomOut::~opZoomOut()
{}
void opZoomOut::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Zoom out is working now");
	pGr->ZOOMING(0.5);
}