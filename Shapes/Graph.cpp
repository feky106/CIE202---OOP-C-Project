#include "Graph.h"
#include "../GUI/GUI.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "..\operations\opDeleteShape.h"

Graph::Graph()
{
	shapeCount = 0;
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes list
	if(shapeCount<maxShapeCount)
		shapesList[shapeCount++] = pShp;	
		std::cout << "Shape ADDED" << endl;
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface

void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (int i=0;i<shapeCount; i++)
		shapesList[i]->Draw(pUI);
	pUI->CreateDrawToolBar2();
}


shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL

	for (int i(0); i < shapeCount; i++) {
		std::cout << i;
		if (shapesList[i]->is_in_fig(x, y))
		{
			return shapesList[i];
			std::cout << endl;

		}
	}
	std::cout << endl;
	return nullptr;
} 


shape* Graph::GetSelected()
{
	return selectedShape;
}

void Graph::SetSelected(shape* s) {
	selectedShape = s;
}

void Graph::SelectList(shape* shape, bool state)
{
	if (state)
	{
		SelectedList[SelectedCount] = shape;
		SelectedCount++;
		std::cout << "\n Add Select" << SelectedCount << endl;

	}
	else {
		for (int i(0); i < SelectedCount; i++)
		{
			if (SelectedList[i] == shape)
			{
				SelectedList[i] = nullptr;
				for (int n(i); n < shapeCount; n++) {
					SelectedList[n] = SelectedList[n + 1];
				}
				SelectedList[SelectedCount] = nullptr;
				SelectedCount--;
				std::cout << "\n Remove Selection" << SelectedCount << endl;

			}
		}

	}
}

bool Graph::CheckSelect(shape* shape) {
	for (int i(0); i < SelectedCount; i++)
	{
		if (SelectedList[i] == shape)
		{
			return true;
			break;
		}
	}
	return false;
}

void Graph::multidelete() {
	for (int i(0); i < SelectedCount; i++)
	{
		Graph::deleteshape(SelectedList[i]);
	}
}

// FEKY |_|_|_|_||_|_|_|_|_||_|_|_|
void Graph::ZOOMING(double s) {
	for (int J = 0; J < shapeCount; J++) {
		shapesList[J]->ZOOM(s);
	}
}




void Graph::deleteshape(shape* pShp) {

	// Check if any shape is selected
	for (int i = 0; i < shapeCount; i++) {
		if (shapesList[i]->IsSelected()) {
			delete shapesList[i];
			shapesList[i] = nullptr;
			for (int n(i); n < shapeCount; n++) {
				shapesList[n] = shapesList[n + 1];
			}
			shapesList[shapeCount] = nullptr;
			shapeCount--;
			std::cout << "Shape Deleted" << endl;
		}
	}
}

void Graph::copy() {
    //Delet the copy list 
    for (int i = 0; i < copiedCount; ++i) {
        delete shapeCopied[i]; // Delete the dynamically allocated object
        shapeCopied[i] = nullptr; // Set the pointer to nullptr
    }
    copiedCount = 0;

    for (int i = 0; i < shapeCount; i++) {
        if (shapesList[i]->IsSelected() == true) {
            shapeCopied[copiedCount] = shapesList[i]->copy();
            shapesList[i]->SetSelected(false);
			copiedCount++;
        }

    }
}

void Graph::cut() {
	//Delet the copy list 
	for (int i = 0; i < copiedCount; ++i) {
		delete shapeCopied[i]; // Delete the dynamically allocated object
		shapeCopied[i] = nullptr; // Set the pointer to nullptr
	}
	copiedCount = 0;

	for (int i = 0; i < shapeCount; i++) {
		if (shapesList[i]->IsSelected() == true) {
			shapeCopied[copiedCount] = shapesList[i]->copy();

			delete shapesList[i];
			shapesList[i] = nullptr;
			for (int n(i); n < shapeCount; n++) {
				shapesList[n] = shapesList[n + 1];
			}
			shapesList[shapeCount] = nullptr;
			shapeCount--;
			std::cout << "Shape Deleted" << endl;
			copiedCount++;
		}
	}
}

void Graph::paste(Point ref)
{
	for (int i(0); i < copiedCount; i++)
	{
		shape* pasted = shapeCopied[i]->pasteShape(ref);
		Graph::Addshape(pasted);

		delete shapeCopied[i];
		shapeCopied[i] = nullptr;
	}
	copiedCount = 0;
}

void Graph::Resize(shape* pFig, double ratio) {
	for (int i = 0; i < shapeCount; i++) {
		if (shapesList[i]->IsSelected()) {
			shapesList[i]->Resize(ratio);
		}
	}
}

void Graph::Rotate(shape* pFig) {
	std::cout << "\n the reotate calles \n ";
	for (int i = 0; i < shapeCount; i++) {
		if (shapesList[i]->IsSelected()) {
			std::cout << "the shape is found \n";

			shapesList[i]->Rotate();
		}
	}
}

void Graph::changeFillCLR(color clr) {
	for (int i = 0; i < shapeCount; i++) {
		if (shapesList[i]->IsSelected()) {

			shapesList[i]->changeFillCLR(clr);
		}
	}
}

void Graph::changeDrowCLR(color clr) {
	for (int i = 0; i < shapeCount; i++) {
		if (shapesList[i]->IsSelected()) {

			shapesList[i]->changeDrowCLR(clr);
		}
	}
}

void Graph::Save(ofstream& outfile) {
	int count = shapeCount;
	outfile << shapeCount << endl;
	outfile << "FORMAT : SHAPENAME   x,y for n points	 redcolorcode	greencolorcode	bluecolorcode	greenforfillcolorcode	blueforfillcolorcode	redforfillcolorcode	penwidth" << endl;
	for (int i = 0; i < count; i++) {
		shapesList[i]->Save(outfile, i + 1);
	}
};



void Graph::load(std::ifstream& inputfile) {
	std::string arr[5];  // Array to store specific parts of the line
	std::string line;

	// Skip the first two lines (assuming the file format requires this)
	for (int i = 0; i < 2; ++i) {
		std::getline(inputfile, line);
	}

	// Now read the third line and process it
	if (std::getline(inputfile, line)) {
		std::istringstream iss(line);

		// Reading specific parts of the third line
		std::getline(iss, arr[0], ' '); // Read first part (e.g., shape name)
		std::getline(iss, arr[1], ' '); // Read second part (e.g., x,y coordinates or other data)
		std::getline(iss, arr[2], ' '); // Read third part (e.g., color code)
		std::getline(iss, arr[3], ' '); // Read fourth part (e.g., another color code)
		std::getline(iss, arr[4]);      // Read the rest of the line

		// Process and print each part of the line
		for (int i = 0; i < 5; ++i) {
			std::cout << arr[i] << endl;
		}
	}
	else {
		std::cerr << "The file does not contain enough lines." << std::endl;
	}
}





// |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_
