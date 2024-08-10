#include "opAddtriangle.h"
#include "../Shapes/triangle.h"
#include "../controller.h"
#include "../GUI\GUI.h"

opAddtriangle::opAddtriangle(controller* pCont) :operation(pCont)
{}
opAddtriangle::~opAddtriangle()
{}

//Execute the operation
void opAddtriangle::Execute()
{
	Point P1, P2, P3;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New triangle: Click at first corner");

	pUI->GetPointClicked(P1.x, P1.y);


	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	
	pUI->GetPointClicked(P2.x, P2.y);

	string msg2 = "Second corner is at (" + to_string(P2.x) + ", " + to_string(P2.y) + " )";
	msg2 += " ... Click at third corner";
	pUI->PrintMessage(msg2);
	//Read 3rd corner and store in point P3
	pUI->GetPointClicked(P3.x, P3.y);

	pUI->ClearStatusBar();



	//Preapre all line parameters
	GfxInfo triangleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	triangleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	triangleGfxInfo.FillClr = pUI->getCrntFillColor();
	triangleGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	pUI->PrintMessage("do you want to be filled ?");
	string t = pUI->GetSrting();
	if (t == "yes") {
		triangleGfxInfo.isFilled = true;
		triangleGfxInfo.isSelected = false;//default is not filled
	}
	else
	{

		triangleGfxInfo.isFilled = false;
		triangleGfxInfo.isSelected = false;//defualt is not selected

	}

	//Create a triangle with the above parameters
	triangle* T = new triangle(P1, P2, P3, triangleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the line to the list of shapes
	pGr->Addshape(T);

}
