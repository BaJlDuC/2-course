#include <iostream>
#include "CCircle.h"
#include "Messages.h"
#include <math.h>
#include <sstream>

using namespace std;

CCircle::CCircle() = default;

CCircle::CCircle(CPoint &centerPointCoords, double circleRadius, uint32_t outlineColorCircle, uint32_t fillColorCircle):
	centerPoint(centerPointCoords),
	radius(circleRadius),
	outlineColor(outlineColorCircle),
	fillColor(fillColorCircle)
{
}

CPoint CCircle::GetCenter()
{
	return centerPoint;
}

double CCircle::GetRadius() const
{
	return radius;
}

double CCircle::GetArea() const
{
	double square = 3.14 * pow(radius, 2);
	return square;
}

double CCircle::GetPerimeter() const
{
	double perimeter = 2 * 3.14 * radius;
	return perimeter;
}

uint32_t CCircle::GetFillColor() const
{
	return fillColor;
}

uint32_t CCircle::GetOutlineColor() const
{
	return outlineColor;
}

string CCircle::ToString() const
{
	stringstream out;
	out.precision(2); 
	out << CIRCLE << endl;
	out << SQUARE << fixed << GetArea() << endl;
	out << PERIMETER << fixed << GetPerimeter() << endl;
	out << RADIUS << fixed << GetRadius() << endl;
	out << OUTLINE_COLOR << GetOutlineColor() << endl;
	out << FILL_COLOR << GetOutlineColor() << endl;
	out << CENTER_X << fixed << centerPoint.GetX() << Y_COORD << fixed << centerPoint.GetY() << endl;
	return out.str();
}