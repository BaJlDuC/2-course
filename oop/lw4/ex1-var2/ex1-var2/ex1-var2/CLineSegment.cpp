#include <iostream>
#include "CLineSegment.h"
#include "Messages.h"
#include <sstream>

using namespace std;

CLineSegment::CLineSegment() = default;

CLineSegment::CLineSegment(CPoint &startLine, CPoint &endLine, uint32_t outlineColorLine)
	:startPoint(startLine), 
	endPoint(endLine), 
	outlineColor(outlineColorLine)
{
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return 0;
}

double CLineSegment::GetLength() const
{
	double length = sqrt(pow((endPoint.GetX() - startPoint.GetX()), 2) + pow((endPoint.GetY() - startPoint.GetY()), 2));
	return length;
}

CPoint CLineSegment::GetStartPoint() const
{
	return startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return endPoint;
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return outlineColor;
}

string CLineSegment::ToString() const
{
	stringstream out;
	out.precision(2);
	out << LINE_SEGMENT << endl;
	out << SQUARE << fixed << GetArea() << endl;
	out << PERIMETER << fixed << GetPerimeter() << endl;
	out << OUTLINE_COLOR << GetOutlineColor() << endl;
	out << START_X << fixed << startPoint.GetX() << Y_COORD << fixed << startPoint.GetY() << endl;
	out << END_X << fixed << endPoint.GetX() << Y_COORD << fixed << endPoint.GetY() << endl;
	out << LENGTH << fixed << GetLength() << endl;
	return out.str();
}