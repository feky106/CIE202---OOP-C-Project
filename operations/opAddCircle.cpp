#include "opAddCircle.h"
#include "../shapes/Circle.h"
#include "../controller.h"
#include "../GUI\GUI.h"

opAddCircle::opAddCircle(controller* pCont) :operation(pCont)
{}
opAddCircle::~opAddCircle()
{}

//Execute the operation
void opAddCircle::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();




	pUI->PrintMessage("Click at the center of the circle");

	pUI->GetPointClicked(P1.x, P1.y);


	string msg = "Center is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second point for radius";
	pUI->PrintMessage(msg);

	pUI->GetPointClicked(P2.x, P2.y);

	//Read radius and store in point P2
	//pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Circle parameters
	GfxInfo CircleGfxInfo;

	//get drawing, filling colors and pen width from the interface

	CircleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CircleGfxInfo.FillClr = pUI->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pUI->getCrntPenWidth();

	pUI->PrintMessage("do you want to be filled ?");
	string t = pUI->GetSrting();

	if (t == "yes") {
		CircleGfxInfo.isFilled = true;
		CircleGfxInfo.isSelected = false;//default is not filled
	}
	else
	{
		CircleGfxInfo.isFilled = false;
		CircleGfxInfo.isSelected = false;//defualt is not selected

	}

	//Create a Circle with the above parameters
	Circle* C = new Circle(P1, P2, CircleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Circle to the list of shapes
	pGr->Addshape(C);
}
