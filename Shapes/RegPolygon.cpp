#include "../Shapes/RegPolygon.h"
#include<iostream>
#include<fstream>

#include <corecrt_math_defines.h>
#include <cmath>
RegPolygon::RegPolygon(Point C, Point* P, int x, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Center = C;
	Point1 = P;
	Vertices_num = x;

	distance = sqrt(pow((Point1->x - Center.x), 2) + pow((Point1->y - Center.y), 2));

	for (int i = 0; i < x; i++) {
		vertixx = Center.x + distance * cos(i * 2 * M_PI / x);
		vertixy = Center.y + distance * sin(i * 2 * M_PI / x);
		ArrX[i] = vertixx;
		ArrY[i] = vertixy;
	}

}

RegPolygon::~RegPolygon()
{}
void RegPolygon::Draw(GUI* pUI) const
{
	//Call Output::DrawRegPolygon to draw a regular Polygon on the screen	
	pUI->DrawRegPolygon(ArrX, ArrY, Vertices_num, ShpGfxInfo);
}

bool RegPolygon::is_in_fig(int x, int y) {
	double RadiusLength = sqrt(pow((Point1->x - Center.x), 2) + pow((Point1->y - Center.y), 2));
	double ClickLength = sqrt(pow((x - Center.x), 2) + pow((y - Center.y), 2));
	if (ClickLength <= RadiusLength) {
		return true;
	}
	else {
		return false;
	}
	return false;
}
string RegPolygon::printforselection() {

	string msg = "selecteed shape is Regular Polygon with  (" + to_string(Vertices_num) + ") Vertices";
	return msg;
}

void RegPolygon::ZOOM(double s) {
	int x = 1300 / 2;
	int y = 650 / 2;
	for (int i = 0; i < Vertices_num; i++) {
		ArrX[i] = (ArrX[i] * s) - (s * x) + x;
		ArrY[i] = (ArrY[i] * s) - (s * y) + y;
	}
}

void RegPolygon::Move(Point P1, Point P2) {
	for (int i = 0; i < Vertices_num; i++) {
		ArrX[i] = P2.x - P1.x + ArrX[i];
		ArrY[i] = P2.y - P1.y + ArrY[i];
	}
}

shape* RegPolygon::copy() {
	RegPolygon* newreg = new RegPolygon(Center, Point1, Vertices_num, ShpGfxInfo);
	return newreg;

	shape* p = new RegPolygon(Center, Point1, Vertices_num, ShpGfxInfo);
	return p;
}

shape* RegPolygon::pasteShape(Point ref)
{
	int dX = Center.x - Point1->x;
	int dY = Center.y - Point1->y;

	Center.x = ref.x;
	Center.y = ref.y;

	Point1->x = ref.x - (dX);
	Point1->y = ref.y - dY;

	RegPolygon* newShape = new RegPolygon(Center, Point1 , Vertices_num, ShpGfxInfo);

	return newShape;
}

void RegPolygon::Resize(double r)
{
	int i = 0;
	int temp;
	while (i < Vertices_num - 1) {
		for (int i = 0; i < Vertices_num; i++) {

			Point npoint1;
			npoint1.x = ArrX[i]; npoint1.y = ArrY[i];
			Point npoint2;
			npoint2.x = ArrX[i + 1]; npoint2.y = ArrY[i + 1];
			double Distance = abs(ArrX[i] - ArrX[i + 1]);
			double x = Distance * r - Distance;
			if (npoint1.x > npoint2.x) {
				npoint1.x += x / 2;
				npoint2.x -= x / 2;
			}
			else {
				npoint1.x -= x / 2;
				npoint2.x += x / 2;
			}
			Distance = abs(ArrY[i] - ArrY[i + 1]);
			x = Distance * r - Distance;
			if (npoint1.y > npoint2.y) {
				npoint1.y += x / 2;
				npoint2.y -= x / 2;
			}
			else {
				npoint1.y -= x / 2;
				npoint2.y += x / 2;
			}
			ArrX[i] = npoint1.x;
			ArrY[i] = npoint1.y;
			ArrX[i + 1] = npoint2.x;
			ArrX[i + 1] = npoint2.y;
			temp = i;
		}break;
	}

	Point npoint1;
	npoint1.x = ArrX[temp]; npoint1.y = ArrY[temp];
	Point npoint2;
	npoint2.x = ArrX[0]; npoint2.y = ArrY[0];
	double Distance = abs(ArrX[temp] - ArrX[0]);
	double x = Distance * r - Distance;
	if (npoint1.x > npoint2.x) {
		npoint1.x += x / 2;
		npoint2.x -= x / 2;
	}
	else {
		npoint1.x -= x / 2;
		npoint2.x += x / 2;
	}
	Distance = abs(ArrY[temp] - ArrY[0]);
	x = Distance * r - Distance;
	if (npoint1.y > npoint2.y) {
		npoint1.y += x / 2;
		npoint2.y -= x / 2;
	}
	else {
		npoint1.y -= x / 2;
		npoint2.y += x / 2;
	}
	ArrX[temp] = npoint1.x;
	ArrY[temp] = npoint1.y;
}

void RegPolygon::Rotate() {
	Point C1 = Center;
	double addx = 0;
	double addy = 0;
	for (int i = 0; i < Vertices_num; i++) {
		addx += ArrX[i];
		addy += ArrY[i];
	}

	for (int i = 0; i < Vertices_num; i++) {
		ArrX[i] -= C1.x; ArrY[i] -= C1.y;
	}

	Point temp;
	for (int i = 0; i < Vertices_num; i++) {
		temp.x = ArrX[i]; temp.y = ArrY[i];
		ArrX[i] = -temp.y; ArrY[i] = temp.x;
	}
	for (int i = 0; i < Vertices_num; i++) {
		ArrX[i] += C1.x; ArrY[i] += C1.y;
	}

}


void RegPolygon::Save(ofstream& OutFile, int id) {

	OutFile << "REGULAR" << " " << Center.x << " " << Center.y << " " << Point1->x << " " << Point1->y << " " << Vertices_num << " ";

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
