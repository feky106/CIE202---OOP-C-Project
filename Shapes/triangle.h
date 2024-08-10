#pragma once
#include "Shape.h"

class triangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	triangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~triangle();
	virtual void Draw(GUI* pUI) const;
	bool is_in_fig(int x, int y);
	virtual string printforselection();
	void Move(Point P1, Point P2);

	Point getP1();

	Point getP2();

	Point getP3();

	GfxInfo GetGfxInfo();
	virtual void Rotate();

	void ZOOM(double s);
	virtual shape* copy();
	virtual shape* pasteShape(Point ref);
	virtual void Resize(double r);
	virtual void Save(ofstream& OutFile, int id);

	//virtual void StickImage(GUI* pUI);

};

