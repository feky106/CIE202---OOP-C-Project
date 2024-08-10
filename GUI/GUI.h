#pragma once



#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
};




class GUI
{
	enum MenuIcon //The icons of the menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here

		//TODO: Add more icons names here
		ICON_ZOOMOUT,
		ICON_ZOOMIN,
		ICON_SELECT,
		ICON_MULTISELECT,
		ICON_MULTIDELETE,
		ICON_MOVE,
		ICON_ROTATE,
		ICON_RESIZE,
		ICON_EXIT,		//Exit icon

		ICON_STICKIMAGE,
		ICON_DEL,

		ICON_COPY,
		ICON_CUT,
		ICON_PASTE,
		ICON_SAVE,

		ICON_FILLCLR,
		ICON_LINECLR,
		ICON_LOAD,
		DRAW_ICON_COUNT,
		//no. of menu icons ==> This should be the last line in this enum

	};

	enum ToolBar2 {
		ICON_RECT,		//Recangle icon in menu
		ICON_TRI,		//Triangle icon in menu
		ICON_REG_POLYGON,
		ICON_LINE,
		ICON_OVAL,
		ICON_SQR,
		ICON_CIRCLE,

		ICON_RED,
		ICON_GREEN,
		ICON_YELLOW,
		ICON_BLUE,
		ToolBar2
	};



	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed



	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreateDrawToolBar2();

	void CreateStatusBar() const;	//create the status bar

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawRegPolygon(int* Arrx, int* ArrY, int x, GfxInfo RegPolygonGfxInfo) const;
	void Drawline(Point P1, Point P2, GfxInfo lineGfxInfo) const;
	void Drawtriangle(Point P1, Point P2, Point P3, GfxInfo triangleGfxInfo) const;
	void DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo) const;
	void DrawOval(Point P1, Point P2, GfxInfo OvalGfxInfo) const;
	void Drawsquare(Point P1, Point P2, GfxInfo SquareGfxInfo) const;
	buttonstate Drag(Point& P2);

	///Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	void ChangeDrowCLR(color clr);
	void ChangeFillCLR(color clr);

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	~GUI();
};

