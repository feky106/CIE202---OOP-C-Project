#include "Circle.h"
#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
#include "../operations/operation.h"
#include "../GUI\GUI.h"
#include "../controller.h"
#include "../operations/opAddCircle.h"

#include<Windows.h>
Circle::Circle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = P1;
	radius = P2;
}
Circle::Circle(Circle* c1) :shape(c1->ShpGfxInfo) {
	c1->Center = Center;
	c1->radius = radius;
	c1->ishiden = ishiden;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawCircle(Center, radius, ShpGfxInfo);
}

bool Circle::is_in_fig(int x, int y) {
	double RadiusLength = sqrt(pow((radius.x - Center.x), 2) + pow((radius.y - Center.y), 2));
	double ClickLength = sqrt(pow((x - Center.x), 2) + pow((y - Center.y), 2));
	if (ClickLength <= RadiusLength) {

		return true;
	}
	else {
		return false;
	}
	return false;

}
string Circle::printforselection() {
	int RadiusLength = sqrt(pow((radius.x - Center.x), 2) + pow((radius.y - Center.y), 2));
	string msg = "selecteed shape is circle with center coordinates  (" + to_string(Center.x) + "," + to_string(Center.y) + ")"
		" and radius(" + to_string(radius.x) + ", " + to_string(radius.y) + ")and raduis Length (" + to_string(RadiusLength) + ")";
	return msg;
}
void Circle::Move(Point P1, Point P2) {
	Center.x = P2.x - P1.x + Center.x;
	radius.x = P2.x - P1.x + radius.x;
	Center.y = P2.y - P1.y + Center.y;
	radius.y = P2.y - P1.y + radius.y;
}
void Circle::Resize(double r)
{

	Point npoint1 = Center;
	Point npoint2 = radius;

	double Distance = abs(radius.x - Center.x);
	double x = Distance * r - Distance;
	if (npoint1.x > npoint2.x) {
		npoint2.x -= x;
	}
	else {
		npoint2.x += x;
	}
	Distance = abs(radius.y - Center.y);
	x = Distance * r - Distance;

	if (npoint1.y > npoint2.y) {
		npoint2.y -= x;
	}
	else {
		npoint2.y += x;
	}
	radius = npoint2;

}


void Circle::ZOOM(double s) {
	int x = 1300 / 2;
	int y = 650 / 2;
	radius.x = (radius.x * s) - (s * x) + x;
	radius.y = (radius.y * s) - (s * y) + y;
	Center.x = (Center.x * s) - (s * x) + x;
	Center.y = (Center.y * s) - (s * y) + y;
}

shape* Circle::copy() {
	// Create a new Circle object with the same properties as "this" object
	Circle* newCircle = new Circle(Center, radius, ShpGfxInfo);
	return newCircle;
}

shape* Circle::pasteShape(Point ref)
{
	int dX = Center.x - radius.x;
	int dY = Center.y - radius.y;

	
	Center.x = ref.x;
	Center.y = ref.y;

	radius.x = ref.x - (dX);
	radius.y = ref.y - dY;
	
	Circle* newShape = new Circle(Center, radius, ShpGfxInfo);

	return newShape;
}


void Circle::Save(ofstream& OutFile, int id) {

	OutFile << "CIRCLE" << " " << Center.x << " " << Center.y << " " << radius.x << " " << radius.y << " ";

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

GfxInfo Circle::GetGfxInfo()
{
	return ShpGfxInfo;
}
Point Circle::getCenter() {
	return Center;
}
Point Circle::getReduis() {
	return radius;
}



//void Circle::StickImage(GUI* pUI) {
//
//	if (SetSelected() == true) {
//		int diffx = sqrt(((Center.x - radius.x) * (Center.x - radius.x)) + ((Center.y - radius.y) * (Center.y - radius.y)));
//		pUI->getwind()->DrawImage("images\\MenuIcons\\Menu_Load.jpg", (Center.x - diffx), (Center.y - diffx), 2 * diffx, 2 * diffx);
//
//	}
//
//}

