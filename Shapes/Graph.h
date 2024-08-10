#pragma once
#include "Shape.h"
#include <fstream>

using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
	enum { maxShapeCount = 1000 };
private:
	shape* shapesList[maxShapeCount]; //a container to hold all shapes							   
	int shapeCount = 0;			// Actual number of shapes stored in the list

	shape* selectedShape;	//pointer to the currently selected shape

	shape* SelectedList[100];
	int SelectedCount = 0;

	shape* SelectedShapesForDelete[100];

	shape* shapeCopied[100];
	int copiedCount = 0;

public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape

	//Feky|_|_|_|_|_|_|_|_|_|_|_|_|_||_|_|_|_|
	
	shape* GetSelected();
	void SetSelected(shape* s);
	void ZOOMING(double s);

	void multiselect(int arrx[], int arry[], int size);
	void SelectList(shape* shape, bool state);
	void multidelete();
	void deleteshape(shape* pShp);

	void copy();
	void cut();
	void paste(Point ref);
	void getCopied(int &x);
	bool CheckSelect(shape* shape);

	void Resize(shape* pFig, double ratio);

	void Rotate(shape* pFig);

	void changeDrowCLR(color clr);
	void changeFillCLR(color clr);

	void Save(ofstream& outfile);
	void load(ifstream& inputfile);

	//|_|_|_|_|_|_|_|_|_|_|_|_|_|

	void setselectedshapenull() {
		selectedShape = nullptr;
	}
};
