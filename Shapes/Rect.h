#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
	bool ishiden = false; 
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();

	virtual void Draw(GUI* pUI) const;

	bool is_in_fig(int x, int y);
	virtual string printforselection();

	virtual void Save(ofstream& OutFile, int id);


	virtual shape* copy();
	virtual shape* pasteShape(Point ref);
	virtual void Rotate();
	void ZOOM(double s);
	virtual void Move(Point P1, Point P2);
	virtual void Resize(double r);

};

