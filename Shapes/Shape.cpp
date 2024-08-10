#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

void shape::setishidentrue()
{
	ishiden = true;
}

void shape::setishidenfalse()
{
	ishiden = false;
}

// Feky |_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_

bool shape::getishiden()
{
	return ishiden;
}

bool shape::InDrawArea(Point P) {
	return (P.x >= 0 && P.x <= 1300 && P.y >= 50 && P.y <= 550);
}

void shape::changeFillCLR(color clr)
{
	ShpGfxInfo.FillClr = clr;
}

void shape::changeDrowCLR(color clr)
{
	ShpGfxInfo.DrawClr = clr;
}


color shape::getdrawclr() {
	return ShpGfxInfo.DrawClr;
}
color shape::getfillclr() {
	return ShpGfxInfo.FillClr;
}
int shape::getborderwidth() {
	return ShpGfxInfo.BorderWdth;
}
bool shape::getisfilled() {
	return ShpGfxInfo.isFilled;
}

//|_|_|_|_|_|_|_|_|_|_|_|_|_