#include "Rect.h"
#include<iostream>
#include<fstream>

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

bool Rect::is_in_fig(int x, int y) {

	if ((x < Corner1.x && x > Corner2.x) || (x > Corner1.x && x < Corner2.x) )
	{
		if ((y < Corner1.y && y > Corner2.y) || (y > Corner1.y && y < Corner2.y))
		{
			return true;
		}
	}
	else { return false; }
}

string Rect::printforselection() {

	string msg = "selecteed shape is rectangle with corner coordinates  (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ") and (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")";
	return msg;
}


void Rect::ZOOM(double s) {
	int x = 1300 / 2;
	int y = 650 / 2;
	Corner1.x = (Corner1.x * s) - (s * x) + x;
	Corner1.y = (Corner1.y * s) - (s * y) + y;
	Corner2.x = (Corner2.x * s) - (s * x) + x;
	Corner2.y = (Corner2.y * s) - (s * y) + y;
}

void Rect::Move(Point P1, Point P2) {
	Corner1.x = P2.x - P1.x + Corner1.x;
	Corner2.x = P2.x - P1.x + Corner2.x;
	Corner1.y = P2.y - P1.y + Corner1.y;
	Corner2.y = P2.y - P1.y + Corner2.y;
}

void Rect::Resize(double r)
{

	Point npoint1 = Corner1;
	Point npoint2 = Corner2;


	double Distance = abs(Corner2.x - Corner1.x);
	double x = Distance * r - Distance;
	if (npoint1.x > npoint2.x) {
		npoint1.x += x / 2;
		npoint2.x -= x / 2;
	}
	else {
		npoint1.x -= x / 2;
		npoint2.x += x / 2;
	}
	Distance = abs(Corner2.y - Corner1.y);
	x = Distance * r - Distance;
	if (npoint1.y > npoint2.y) {
		npoint1.y += x / 2;
		npoint2.y -= x / 2;
	}
	else {
		npoint1.y -= x / 2;
		npoint2.y += x / 2;
	}
	Corner1 = npoint1;
	Corner2 = npoint2;
}

void Rect::Rotate() {
	Point C1;
	C1.x = (Corner1.x + Corner2.x) / 2;
	C1.y = (Corner1.y + Corner2.y) / 2;
	Corner1.x -= C1.x; Corner1.y -= C1.y;
	Corner2.x -= C1.x; Corner2.y -= C1.y;
	Point temp;
	temp.x = Corner1.x; temp.y = Corner1.y;
	Corner1.x = -temp.y; Corner1.y = temp.x;

	temp.x = Corner2.x; temp.y = Corner2.y;
	Corner2.x = -temp.y; Corner2.y = temp.x;


	Corner1.x += C1.x; Corner1.y += C1.y;
	Corner2.x += C1.x; Corner2.y += C1.y;
}

shape* Rect::copy() {

	Rect* newRectangle = new Rect(Corner1, Corner2, ShpGfxInfo);
	return newRectangle;
}

shape* Rect::pasteShape(Point ref) 
{
	int dX = Corner1.x - Corner2.x;
	int dY = Corner1.y - Corner2.y;

	Corner1.x = ref.x;
	Corner1.y = ref.y;

	Corner2.x = ref.x - (dX);
	Corner2.y = ref.y - dY;

	Rect* newShape = new Rect(Corner1, Corner2, ShpGfxInfo);

	return newShape;
}


void Rect::Save(ofstream& OutFile, int id)
{

	OutFile << "RECT" << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";

	OutFile << shape::getdrawclr().getucred() << " ";
	OutFile << shape::getdrawclr().getucgreen() << " ";
	OutFile << shape::getdrawclr().getucblue() << " ";
	if (shape::getisfilled() == true) {
		OutFile << shape::getfillclr().getucred() << " ";
		OutFile << shape::getfillclr().getucgreen() << " ";
		OutFile << shape::getfillclr().getucblue() << " ";
	}
	else
	{
		OutFile << "NO_FILL" << " ";
	}
	OutFile << shape::getborderwidth() << " ";
	OutFile << "END" << " ";
}