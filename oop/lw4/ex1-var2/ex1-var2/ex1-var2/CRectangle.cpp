#include <iostream>
#include <cmath>
#include "CRectangle.h"
#include "Messages.h"
#include <sstream>
#include <iomanip>

using namespace std;

CRectangle::CRectangle() = default;

CRectangle::CRectangle(CPoint &leftTopRectangle, CPoint &rightBottomRectangle, uint32_t outlineColorRectangle, uint32_t fillColorRectangle) :
	leftTop(leftTopRectangle),
	rightBottom(rightBottomRectangle),
	outlineColor(outlineColorRectangle),
	fillColor(fillColorRectangle)
{
}

CPoint CRectangle::GetLeftTop()
{
	return leftTop;
}

CPoint CRectangle::GetRightBottom()
{
	return rightBottom;
}

double CRectangle::GetWidth() const
{
	double width = abs(leftTop.GetY() - rightBottom.GetY());
	return width;
}

double CRectangle::GetHeight() const
{
	double height = abs(leftTop.GetX() - rightBottom.GetX());
	return height;
}

double CRectangle::GetArea() const
{
	double square = GetWidth() * GetHeight();
	return square;
}

double CRectangle::GetPerimeter() const
{
	double perimeter = 2 * (GetWidth() + GetHeight());
	return perimeter;
}

string CRectangle::ToString() const
{
	stringstream out;
	out.precision(2);
	out << RECTANGLE << endl;
	out << SQUARE << fixed << GetArea() << endl;
	out << PERIMETER << fixed << GetPerimeter() << endl;
	out << OUTLINE_COLOR << GetOutlineColor() << endl;
	out << FILL_COLOR << GetOutlineColor() << endl;
	out << LEFT_TOP_X << fixed << leftTop.GetX() << Y_COORD << fixed << leftTop.GetY() << endl;
	out << RIGHT_BOTTOM_X << fixed << rightBottom.GetX() << Y_COORD << fixed << rightBottom.GetY() << endl;
	out << RECTANGLE_WIDTH << fixed << GetWidth() << endl;
	out << RECTANGLE_HEIGHT << fixed << GetHeight() << endl;
	return out.str();
}

uint32_t CRectangle::GetFillColor() const
{
	return fillColor;
}

uint32_t CRectangle::GetOutlineColor() const
{
	return outlineColor;
}