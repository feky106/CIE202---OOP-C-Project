#pragma once
#include "../shapes/Shape.h"
class RegPolygon :
	public shape
{
private:
	Point Center;
	Point* Point1;
	int distance;
	int Vertices_num;
	int arrdiffinx[200];
	int arrdiffiny[200];
	int* ArrX = new int[2000];
	int* ArrY = new int[2000];
	int vertixx;
	int vertixy;

public:
	RegPolygon(Point, Point*, int, GfxInfo shapeGfxInfo);
	virtual ~RegPolygon();
	virtual void Draw(GUI* pUI) const;
	bool is_in_fig(int x, int y);
	virtual string printforselection();
	virtual void Rotate();
	void ZOOM(double s);
	virtual shape* copy();
	virtual void Move(Point P1, Point P2);
	virtual shape* pasteShape(Point ref);
	virtual void Save(ofstream& OutFile, int id);
	virtual void Resize(double r);

};

