#include "line.h"
#include<iostream>
#include<fstream>
#include <cmath>

#include <time.h>
#include "../GUI/GUI.h"
#include "../controller.h"
#include "../operations/operation.h"
#include <corecrt_math_defines.h>

line::line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;

}

line::~line()
{}

void line::Draw(GUI* pUI) const
{
	//Call Output::Drawline to draw a line on the screen	
	pUI->Drawline(Corner1, Corner2, ShpGfxInfo);
}
void line::Move(Point P1, Point P2) {

	Corner1.x = P2.x - P1.x + Corner1.x;
	Corner2.x = P2.x - P1.x + Corner2.x;
	Corner1.y = P2.y - P1.y + Corner1.y;
	Corner2.y = P2.y - P1.y + Corner2.y;
}

void line::Resize(double r)
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

bool line::is_in_fig(int x, int y) {

	int LineLength = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	int Line1 = sqrt(pow((Corner1.x - x), 2) + pow((Corner1.y - y), 2));
	int Line2 = sqrt(pow((x - Corner2.x), 2) + pow((y - Corner2.y), 2));
	if (Line1 + Line2 == LineLength) {
		return true;

	}
	else {
		return false;
	}
};
string line::printforselection() {
	int LineLength = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	string msg = "selecteed shape is line with coordinates  (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")"
		" and (" + to_string(Corner2.x) + ", " + to_string(Corner2.y) + ")and Length (" + to_string(LineLength) + ")";
	return msg;
}

void line::ZOOM(double s) {
	int x = 1300 / 2;
	int y = 650 / 2;
	Corner1.x = (Corner1.x * s) - (s * x) + x;
	Corner1.y = (Corner1.y * s) - (s * y) + y;
	Corner2.x = (Corner2.x * s) - (s * x) + x;
	Corner2.y = (Corner2.y * s) - (s * y) + y;
}

shape* line::copy()
{
	line* newLine = new line(Corner1, Corner2, ShpGfxInfo);
	return newLine;
}

void line::Save(ofstream& OutFile, int id) {

	OutFile << "LINE" << " " << ShapeID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";

	OutFile << shape::getdrawclr().getucred() << " ";
	OutFile << shape::getdrawclr().getucgreen() << " ";
	OutFile << shape::getdrawclr().getucblue() << " ";
	OutFile << shape::getborderwidth() << " ";
	OutFile << "END" << " ";
}

shape* line::pasteShape(Point ref)
{
	int dX = Corner1.x - Corner2.x;
	int dY = Corner1.y - Corner2.y;

	Corner1.x = ref.x;
	Corner1.y = ref.y;

	Corner2.x = ref.x - (dX);
	Corner2.y = ref.y - dY;

	line* newLine = new line(Corner1, Corner2, ShpGfxInfo);

	return newLine;
}

void line::Rotate() {
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

Point line::getP1() {
	return Corner1;
}
Point line::getP2() {
	return Corner2;
}
GfxInfo line::GetGfxInfo()
{
	return ShpGfxInfo;
}
