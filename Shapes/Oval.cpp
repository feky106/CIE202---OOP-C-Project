#include "Oval.h"

#include<iostream>
#include<fstream>
#include <cmath>
#include <corecrt_math_defines.h>
Oval::Oval(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
	ShapeID = ID;
}

Oval::~Oval()
{}
void Oval::Resize(double r) {
	Point npoint1 = Point1;
	Point npoint2 = Point2;


	double Distance = abs(Point2.x - Point1.x);
	double x = Distance * r - Distance;
	if (npoint1.x > npoint2.x) {
		npoint1.x += x / 2;
		npoint2.x -= x / 2;
	}
	else {
		npoint1.x -= x / 2;
		npoint2.x += x / 2;
	}
	Distance = abs(Point2.y - Point1.y);
	x = Distance * r - Distance;
	if (npoint1.y > npoint2.y) {
		npoint1.y += x / 2;
		npoint2.y -= x / 2;
	}
	else {
		npoint1.y -= x / 2;
		npoint2.y += x / 2;
	}
	Point1 = npoint1;
	Point2 = npoint2;
}
void Oval::Move(Point P1, Point P2) {
	Point1.x = P2.x - P1.x + Point1.x;
	Point2.x = P2.x - P1.x + Point2.x;
	Point1.y = P2.y - P1.y + Point1.y;
	Point2.y = P2.y - P1.y + Point2.y;
}
void Oval::Rotate() {
	Point C1;
	C1.x = (Point1.x + Point2.x) / 2;
	C1.y = (Point1.y + Point2.y) / 2;
	Point1.x -= C1.x; Point1.y -= C1.y;
	Point2.x -= C1.x; Point2.y -= C1.y;
	Point temp;
	temp.x = Point1.x; temp.y = Point1.y;
	Point1.x = -temp.y; Point1.y = temp.x;

	temp.x = Point2.x; temp.y = Point2.y;
	Point2.x = -temp.y; Point2.y = temp.x;


	Point1.x += C1.x; Point1.y += C1.y;
	Point2.x += C1.x; Point2.y += C1.y;
}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawOval to draw a Oval on the screen	
	pUI->DrawOval(Point1, Point2, ShpGfxInfo); {}
}
bool Oval::is_in_fig(int x, int y) {
	double h = (Point1.x + Point2.x) / 2;
	double k = (Point1.y + Point2.y) / 2;
	double a = sqrt(pow((Point1.x - h), 2));
	double b = sqrt(pow((Point1.y - k), 2));
	if ((pow((x - h), 2) / pow(a, 2)) + (pow((y - k), 2) / pow(b, 2)) <= 1) {
		return true;
	}
	else {
		return false;
	}
}
string Oval::printforselection() {
	int h = (Point1.x + Point2.x) / 2;
	int k = (Point1.y + Point2.y) / 2;
	int a = sqrt(pow((Point1.x - h), 2));
	int b = sqrt(pow((Point1.y - k), 2));
	string msg = "selecteed shape is Oval with center (" + to_string(h) + " ," + to_string(k) + ") and axis(" + to_string(a) + ") and (" + to_string(b) + ")";
	return msg;
}




void Oval::ZOOM(double s) {
	int x = 1300 / 2;
	int y = 650 / 2;
	Point1.x = (Point1.x * s) - (s * x) + x;
	Point1.y = (Point1.y * s) - (s * y) + y;
	Point2.x = (Point2.x * s) - (s * x) + x;
	Point2.y = (Point2.y * s) - (s * y) + y;


	;
}
shape* Oval::pasteShape(Point ref)
{
	int dX = Point1.x - Point2.x;
	int dY = Point1.y - Point2.y;

	Point1.x = ref.x;
	Point1.y = ref.y;

	Point2.x = ref.x - (dX);
	Point2.y = ref.y - dY;

	Oval* newShape = new Oval(Point1, Point2, ShpGfxInfo);

	return newShape;
}
shape* Oval::copy() {

	Oval* newOval = new Oval(Point1, Point2, ShpGfxInfo);
	return newOval;
}


void Oval::Save(ofstream& OutFile, int id) {
	OutFile << "OVAL" << " " << Point1.x << " " << Point1.y << " " << Point2.x << " " << Point2.y << " ";

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

//void Oval::StickImage(GUI* pUI) {
//	if (ishiden == true) {
//
//		int width = sqrt(pow((Point1.x - Point2.x), 2) + pow((Point1.y - Point1.y), 2));
//		int height = sqrt(pow((Point1.x - Point1.x), 2) + pow((Point1.y - Point2.y), 2));
//		pUI->getwind()->DrawImage("images\\MenuIcons\\Menu_Load.jpg", min(Point1.x, Point2.x), min(Point1.y, Point2.y), width, height);
//	}
Point Oval::getPoint1() {
	return Point1;
}
GfxInfo Oval::GetGfxInfo()
{
	return ShpGfxInfo;
}
Point Oval::getPoint2()
{
	return Point2;
}
