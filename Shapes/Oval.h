#pragma once
#include "Shape.h"
class Oval :
	public shape
{
private:
	Point Point1;
	Point Point2;
	bool ishiden = false;
	int ShapeID;
	bool isingroup = false;
public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();

	virtual void Draw(GUI* pUI) const;
	bool is_in_fig(int x, int y);
	virtual string printforselection();
	void Move(Point P1, Point P2);
	virtual void Rotate();

	shape* copy();

	Point getPoint1();

	GfxInfo GetGfxInfo();

	virtual void Save(ofstream& OutFile, int id);

	Point getPoint2();

	void ZOOM(double s);

	virtual shape* pasteShape(Point ref);

	virtual void Resize(double r);

};


