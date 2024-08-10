#pragma once
#include "Shape.h"
class Circle :
    public shape
{
private:
	Point Center;
	Point radius;

public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	Circle(Circle* c1);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;

	virtual string printforselection();
	void Move(Point P1, Point P2);
	virtual void Resize(double r);
	virtual void Rotate() {};

	bool is_in_fig(int x, int y);


	shape* copy();
	virtual shape* pasteShape(Point ref);

	//virtual void StickImage(GUI* pUI);
	GfxInfo GetGfxInfo();
	Point getCenter();
	Point getReduis();

	void changeFillCLR(color clr);

	virtual void Save(ofstream& OutFile, int id);




	void ZOOM(double  s);

};
