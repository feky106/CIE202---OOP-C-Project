#include "controller.h"
#include "operations\opAddRect.h"
#include "operations/opAddLine.h"
// |_|_|_|_|_|
#include "operations/opSelect.h"
#include "operations/opAddRegPolygon.h"
#include "operations/opAddtriangle.h"
#include "operations/opAddCircle.h"
#include "operations/opAddsquare.h"
#include "operations/opAddOval.h"

#include "operations/opMultiSelect.h"
#include "operations/opZoomIn.h"
#include "operations/opZoomOut.h"
#include "operations/opMultiDelete.h"
#include "operations/opDeleteShape.h"
#include "operations/opMove.h"
#include "operations/opResize.h"
#include "operations/opRotate.h"


#include "operations/opCopy.h"
#include "operations/opcut.h"
#include "operations/opPaste.h"
#include "operations/opsave.h"
#include "operations/opload.h"

#include "operations/opChangeLineCLR.h"
#include "operations/opChangeFillCLR.h"
//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;

		case EXIT:
			///create Exitoperation here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;

		// FEKY |_|_|_|_|_|_|_|_|_|_|_|_

		case SELECT:
			pOp = new opSelect(this);
			break;
			/*
		case STICK:
			pOp = new opStickImage(this);
			break;
			*/
		case DRAW_REGPOLYGON:
			pOp = new opAddRegPolygon(this);
			break;


		case MULTI_SELECT:
			pOp = new opMultiSelect(this);
			break;

		case ZOOMIN:
			pOp = new opZoomIn(this);
			break;
		case ZOOMOUT:
			pOp = new opZoomOut(this);
			break;
		case MOVE:
			pOp = new opMove(this);
			break;

		case DRAW_LINE:
			pOp = new opAddline(this);
			break;
		case DRAW_TRI:
			pOp = new opAddtriangle(this);
			break;
		case DEL:
			pOp = new opdeleteshape(this);
			break;
		case COPY:
			pOp = new opCopy(this);
			break;
		case CUT:
			pOp = new opcut(this);
			break;
		case PASTE:
			pOp = new opPaste(this);
			break;
		case MULTI_DELETE: 
			pOp = new opMultiDelete(this);
			break;
		case DROW_CIR:
			pOp = new opAddCircle(this);
			break;
		case DROW_SQR:
			pOp = new opAddsquare(this);
			break;
		case DROW_OVAL:
			pOp = new opAddOval(this);
			break;

		case RESIZE:
			pOp = new opResize(this);
			break;
		case ROTATE:
			pOp = new opRotate(this);
			break;
		case CHANGE_LINECLR:
			pOp = new opChangeLineCLR(this);
			break;
		case CHANGE_FILLCLR:
			pOp = new opChangeFillCLR(this);
			break;
		case SAVE:
			pOp = new opsave(this);
			break;
		case LOAD:
			pOp = new opload(this);
			break;
	}
	return pOp;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}