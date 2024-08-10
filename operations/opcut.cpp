#include"opcut.h"
#include"../Shapes/Graph.h"
#include"../controller.h"
#include"../operations/operation.h"

opcut::opcut(controller* pCont) : operation(pCont) {}

void opcut::Execute()
{
    GUI* pUI = pControl->GetUI();
    Graph* pGr = pControl->getGraph();
    pGr->cut();

}
