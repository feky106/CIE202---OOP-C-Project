#pragma once
#include "Shape.h"

class square :
	public shape
{
private:
	Point Corner1;
	Point Corner2;

public:
	square(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~square();

	virtual void Draw(GUI* pUI) const;
	bool is_in_fig(int x, int y);

	void Move(Point P1, Point P2);
	virtual void Resize(double r);

	virtual string printforselection();

	virtual void Rotate() {};
	shape* copy();

	GfxInfo GetGfxInfo();

	Point getP1();

	Point getP2();

	virtual shape* pasteShape(Point ref);
	void ZOOM(double s);

	virtual void Save(ofstream& OutFile, int id);

	//virtual void StickImage(GUI* pUI);

};

