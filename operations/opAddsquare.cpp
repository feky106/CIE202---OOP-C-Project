#include "opAddsquare.h"
#include "../shapes/square.h"

#include "../controller.h"

#include "../GUI\GUI.h"

opAddsquare::opAddsquare(controller* pCont) :operation(pCont)
{}
opAddsquare::~opAddsquare()
{}

//Execute the operation
void opAddsquare::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New square: Click at first corner");

	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);


	pUI->GetPointClicked(P2.x, P2.y);

	pUI->ClearStatusBar();
	//P2.y = P1.y + (P2.x - P1.x);

	//Preapre all square parameters
	GfxInfo squareGfxInfo;

	//get drawing, filling colors and pen width from the interface
	squareGfxInfo.DrawClr = pUI->getCrntDrawColor();
	squareGfxInfo.FillClr = pUI->getCrntFillColor();
	squareGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	pUI->PrintMessage("do you want to be filled ?");
	string t = pUI->GetSrting();
	if (t == "yes") {
		squareGfxInfo.isFilled = true;
		squareGfxInfo.isSelected = false;//default is not filled
	}
	else
	{

		squareGfxInfo.isFilled = false;
		squareGfxInfo.isSelected = false;//defualt is not selected

	}


	//Create a square with the above parameters
	square* S = new square(P1, P2, squareGfxInfo);
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the square to the list of shapes
	pGr->Addshape(S);

}
