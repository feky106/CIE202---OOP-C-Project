#pragma once

#include "Shape.h"
class line :public shape
{
private:
	Point Corner1;
	Point Corner2;
	bool ishiden = false;
	int ShapeID;
	bool isingroup = false;
public:
	line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~line();

	virtual void Draw(GUI* pUI) const;
	bool is_in_fig(int x, int y);
	virtual string printforselection();

	shape* copy();
	virtual shape* pasteShape(Point ref);

	void Rotate();
	void Move(Point P1, Point P2);
	virtual void Resize(double r);

	virtual void Save(ofstream& OutFile, int id);

	void ZOOM(double s);

	Point getP1();

	Point getP2();

	GfxInfo GetGfxInfo();

};