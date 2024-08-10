#include "square.h"
#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
square::square(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner2.y = Corner1.y + (Corner2.x - Corner1.x);


}

square::~square()
{}

void square::Move(Point P1, Point P2) {
	Corner1.x = P2.x - P1.x + Corner1.x;
	Corner2.x = P2.x - P1.x + Corner2.x;
	Corner1.y = P2.y - P1.y + Corner1.y;
	Corner2.y = P2.y - P1.y + Corner2.y;
}

void square::Resize(double r)
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


void square::Draw(GUI* pUI) const
{
	//Call Output::Drawsquare to draw a square on the screen	
	pUI->Drawsquare(Corner1, Corner2, ShpGfxInfo);
}

bool square::is_in_fig(int x, int y) {
	if ((x > Corner1.x && x < Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else if ((x < Corner1.x && x > Corner2.x && y > Corner1.y && y < Corner2.y))
	{
		return true;
	}
	else if ((x < Corner1.x && x > Corner2.x && y < Corner1.y && y > Corner2.y))
	{
		return true;
	}
	else if ((x > Corner1.x && x < Corner2.x && y < Corner1.y && y > Corner2.y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
string square::printforselection() {
	double Length = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner2.y), 2));
	string msg = "selecteed shape is square with side length (" + to_string(Length) + ")";
	return msg;
}

void square::ZOOM(double s) {
	int x = 1300 / 2;
	int y = 650 / 2;
	Corner1.x = (Corner1.x * s) - (s * x) + x;
	Corner1.y = (Corner1.y * s) - (s * y) + y;
	Corner2.x = (Corner2.x * s) - (s * x) + x;
	Corner2.y = (Corner2.y * s) - (s * y) + y;
}
shape* square::copy() {

	square* newSquare = new square(Corner1, Corner2, ShpGfxInfo);
	return newSquare;
}
//void square::StickImage(GUI* pUI) {
//	if (ishiden == true) {
//
//		int width = sqrt(pow((Corner1.x - Corner2.x), 2) + pow((Corner1.y - Corner1.y), 2));
//		int height = sqrt(pow((Corner1.x - Corner1.x), 2) + pow((Corner1.y - Corner2.y), 2));
//
//		pUI->getwind()->DrawImage("images\\MenuIcons\\Menu_Load.jpg", min(Corner1.x, Corner2.x), min(Corner1.y, Corner2.y), width, height);
//	}
GfxInfo square::GetGfxInfo()
{
	return ShpGfxInfo;
}
Point square::getP1() {
	return Corner1;
}
Point square::getP2() {
	return Corner2;
}

shape* square::pasteShape(Point ref)
{
	int dX = Corner1.x - Corner2.x;
	int dY = Corner1.y - Corner2.y;

	Corner1.x = ref.x;
	Corner1.y = ref.y;

	Corner2.x = ref.x - (dX);
	Corner2.y = ref.y - dY;

	square* newShape = new square(Corner1, Corner2, ShpGfxInfo);

	return newShape;
}

void square::Save(ofstream& OutFile, int id) {
	OutFile << "SQUARE" << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " ";

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