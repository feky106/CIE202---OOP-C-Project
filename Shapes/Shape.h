#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	bool ishiden = false;
	
	/// Add more parameters if needed.

public:
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color

	//     Feky |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_
	virtual string printforselection() = 0;
	virtual bool is_in_fig(int x, int y) = 0;

	void setishidentrue();
	void setishidenfalse();
	bool getishiden();

	bool InDrawArea(Point P);

	virtual void Save(ofstream& OutFile, int id) = 0;
	virtual void  ZOOM(double s) = 0;
	virtual void Move(Point P1, Point P2) =0;
	virtual shape* copy() = 0;
	virtual shape* pasteShape(Point c) = 0;

	void changeFillCLR(color clr);
	void changeDrowCLR(color clr);

	color getdrawclr();
	color getfillclr();
	int getborderwidth();
	bool getisfilled();
	// |_|_|_|_|

	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	


	virtual void Rotate() = 0;	//Rotate the shape
	virtual void Resize(double r) = 0;	//Resize the shape
	//virtual void Move() = 0;		//Move the shape

	//virtual void Save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar
};

