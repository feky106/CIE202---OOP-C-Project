#include "opAddRegPolygon.h"
#include "../shapes/RegPolygon.h"
#include "../controller.h"
#include "../GUI/GUI.h"

opAddRegPolygon::opAddRegPolygon(controller* pCont) :operation(pCont)
{}
opAddRegPolygon::~opAddRegPolygon()
{}

//Execute the operation
void opAddRegPolygon::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Point Center;

	pUI->PrintMessage("New regular Polygon: Click on Center");

	pUI->GetPointClicked(Center.x, Center.y);

	string msg = "Center is at (" + to_string(Center.x) + ", " + to_string(Center.y) + " )";
	msg += " ... Enter number of vetices";
	pUI->PrintMessage(msg);
	string x = pUI->GetSrting();
	Point* array = new Point[stoi(x)];
	string msg2 = "Your vertices are (" + x + " )";

	//Read number of vertices


	msg2 += " ... Click on your First Vertex";
	pUI->PrintMessage(msg2);
	//Read Points

	pUI->GetPointClicked(array[0].x, array[0].y);


	pUI->ClearStatusBar();

	//Preapre all Irregular Polygon parameters
	GfxInfo RegPolygonGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RegPolygonGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RegPolygonGfxInfo.FillClr = pUI->getCrntFillColor();
	RegPolygonGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	pUI->PrintMessage("do you want to be filled ?");
	string t = pUI->GetSrting();
	if (t == "yes") {
		RegPolygonGfxInfo.isFilled = true;
		RegPolygonGfxInfo.isSelected = false;//default is not filled
	}
	else
	{

		RegPolygonGfxInfo.isFilled = false;
		RegPolygonGfxInfo.isSelected = false;//defualt is not selected

	}

	//Create an Irregular Polygon with the above parameters
	RegPolygon* I = new RegPolygon(Center, array, stoi(x), RegPolygonGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Circle to the list of shapes
	pGr->Addshape(I);



}
