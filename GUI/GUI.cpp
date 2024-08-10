#include "GUI.h"
#include <iostream>

GUI::GUI()
{

	width = 1300;
	height = 700;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 60;

	DrawColor = DARKGREEN;	//default Drawing color
	FillColor = YELLOW;	//default Filling color
	MsgColor = BLUE;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use it for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateDrawToolBar2();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	//[1] If user clicks on the Toolbar
	if (y >= 0 && y < ToolBarHeight)
	{
		//Check whick Menu icon was clicked
		//==> This assumes that menu icons are lined up horizontally <==
		int ClickedIconOrder = (x / MenuIconWidth);
		//Divide x coord of the point clicked by the menu icon width (int division)
		//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

		switch (ClickedIconOrder)
		{

		//Feky |_|_|_|_|_|_
		case ICON_SELECT: return SELECT;
		case ICON_ZOOMIN: return ZOOMIN;
		case ICON_ZOOMOUT: return ZOOMOUT;
		case ICON_STICKIMAGE: return STICK;
		case ICON_MULTISELECT: return MULTI_SELECT;
		case ICON_MULTIDELETE: return MULTI_DELETE;
		case ICON_MOVE: return MOVE;
		case ICON_ROTATE: return ROTATE;


		case ICON_DEL: return DEL;
		case ICON_COPY: return COPY;
		case ICON_CUT: return CUT;
		case ICON_PASTE: return PASTE;
		case ICON_EXIT: return EXIT;
		case ICON_RESIZE: return RESIZE;

		case ICON_SAVE: return SAVE;
		case ICON_LOAD: return LOAD;
		case ICON_FILLCLR: return CHANGE_FILLCLR;
		case ICON_LINECLR: return CHANGE_LINECLR;


		default: return EMPTY;	//A click on empty place in desgin toolbar
		}
	}
	if (x >= 0 && x < 50)
	{
		int clickontoolbar2 = ((y / 50) - 1);
		switch (clickontoolbar2)
		{
		case ICON_RECT: return DRAW_RECT;
		case ICON_TRI: return DRAW_TRI;
		case ICON_REG_POLYGON: return DRAW_REGPOLYGON;
		case ICON_LINE: return DRAW_LINE;
		case ICON_SQR: return DROW_SQR;
		case ICON_OVAL: return DROW_OVAL;
		case ICON_CIRCLE: return DROW_CIR;
		}

	}

	//[2] User clicks on the drawing area
	if (y >= ToolBarHeight && y < height - StatusBarHeight)
	{
		return DRAWING_AREA;
	}

	//[3] User clicks on the status bar
	return STATUS;
	

}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";
	MenuIconImages[ICON_SELECT] = "images\\MenuIcons\\Select.jfif";
	MenuIconImages[ICON_ZOOMIN] = "images\\MenuIcons\\ZoomIn.jpg";
	MenuIconImages[ICON_ZOOMOUT] = "images\\MenuIcons\\ZoomOut.jpg";
	MenuIconImages[ICON_STICKIMAGE] = "images\\MenuIcons\\StickImage.jpg";
	MenuIconImages[ICON_MULTISELECT] = "images\\MenuIcons\\MultiSelect.jpg";
	MenuIconImages[ICON_MULTIDELETE] = "images\\MenuIcons\\MultiDelete.jpg";
	MenuIconImages[ICON_MOVE] = "images\\MenuIcons\\move.jpg";
	MenuIconImages[ICON_DEL] = "images\\MenuIcons\\delete.jpg";
	MenuIconImages[ICON_COPY] = "images\\MenuIcons\\copy.jpeg";
	MenuIconImages[ICON_CUT] = "images\\MenuIcons\\cut.jpeg";
	MenuIconImages[ICON_PASTE] = "images\\MenuIcons\\paste.jpeg";
	MenuIconImages[ICON_ROTATE] = "images\\MenuIcons\\rotate.jpeg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\save.jpeg";
	MenuIconImages[ICON_RESIZE] = "images\\MenuIcons\\resize.jpeg";
	MenuIconImages[ICON_FILLCLR] = "images\\MenuIcons\\fillclr.jpeg";
	MenuIconImages[ICON_LINECLR] = "images\\MenuIcons\\lineclr.jpeg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\load.jpeg";





	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}

void GUI::CreateDrawToolBar2()
{
	// ...
	// Calculate the width and height of each icon in the vertical toolbar
	int iconWidth = ToolBarHeight;
	int iconHeight = 50;
	string MenuIconImages2[ToolBar2];
	MenuIconImages2[ICON_SQR] = "images\\MenuIcons\\squre.jpg";
	MenuIconImages2[ICON_OVAL] = "images\\MenuIcons\\oval.jpg";
	MenuIconImages2[ICON_REG_POLYGON] = "images\\MenuIcons\\RegPol.jpg";
	MenuIconImages2[ICON_LINE] = "images\\MenuIcons\\line.jpg";
	MenuIconImages2[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages2[ICON_TRI] = "images\\MenuIcons\\triangle.jpeg";
	MenuIconImages2[ICON_CIRCLE] = "images\\MenuIcons\\circle.jpg";

	MenuIconImages2[ICON_RED] = "images\\MenuIcons\\red.jpeg";
	MenuIconImages2[ICON_BLUE] = "images\\MenuIcons\\blue.jpeg";
	MenuIconImages2[ICON_YELLOW] = "images\\MenuIcons\\yellow.jpeg";
	MenuIconImages2[ICON_GREEN] = "images\\MenuIcons\\green.jpeg";

	// Draw the vertical toolbar
	for (int i = 0; i < ToolBar2; i++) {
		pWind->DrawImage(MenuIconImages2[i], 0, ((i + 1) * iconHeight) , iconWidth, iconHeight);
	}

	// Draw a line to the right of the vertical toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(50, 40, iconWidth, height);
}
//////////////////////////////////////////////////////////////////////////////////////////



void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
void GUI::ChangeDrowCLR(color CLR)
{
	DrawColor = CLR;
}
void GUI::ChangeFillCLR(color clr)
{
	FillColor = clr;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}


void GUI::DrawRegPolygon(int* Arrx, int* ArrY, int x, GfxInfo RegPolygonGfxInfo) const
{
	color DrawingClr;
	if (RegPolygonGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RegPolygonGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RegPolygonGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RegPolygonGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RegPolygonGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(Arrx, ArrY, x, style);
}

void GUI::Drawline(Point P1, Point P2, GfxInfo lineGfxInfo) const
{
	color DrawingClr;
	if (lineGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = lineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, lineGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (lineGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(lineGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}

void GUI::Drawtriangle(Point P1, Point P2, Point P3, GfxInfo triangleGfxInfo) const
{
	color DrawingClr;
	if (triangleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = triangleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, triangleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (triangleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(triangleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}


void GUI::DrawCircle(Point P1, Point P2, GfxInfo CircleGfxInfo) const
{
	color DrawingClr;
	if (CircleGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = CircleGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (CircleGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(CircleGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, sqrt(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y), 2)), style);
	GUI::CreateStatusBar();
}

void GUI::DrawOval(Point P1, Point P2, GfxInfo OvalGfxInfo) const
{

	color DrawingClr;
	if (OvalGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = OvalGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, OvalGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (OvalGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OvalGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);

}

void GUI::Drawsquare(Point P1, Point P2, GfxInfo SquareGfxInfo) const
{
	color DrawingClr;
	if (SquareGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

buttonstate GUI::Drag(Point& P2) {
	return pWind->GetButtonState(LEFT_BUTTON, P2.x, P2.y);
}

