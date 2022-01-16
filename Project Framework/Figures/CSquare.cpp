#include "CSquare.h"

CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
}


void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);


}
void CSquare::Save(ofstream &OutFile)
{
	OutFile << "Square\t" << ID << "\t" << this->TopLeftCorner.x << "\t" << this->TopLeftCorner.y << "\t"
		<< this->getColor(this->FigGfxInfo.DrawClr) << "\n"

}
