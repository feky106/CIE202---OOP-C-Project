#include "opZoomIn.h"
#include "opZoomIn.h"
#include "..\controller.h"
#include "operation.h"
#include "..\GUI\GUI.h"
#include "..\controller.h"
#include"../Shapes/Graph.h"

opZoomIn::opZoomIn(controller* pCont) :operation(pCont)
{}
opZoomIn::~opZoomIn()
{}
void opZoomIn::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Zoom in is working now");
	pGr->ZOOMING(2);
}