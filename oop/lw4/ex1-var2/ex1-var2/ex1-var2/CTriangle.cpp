#include <iostream>
#include <string>
#include <stdint.h>
#include <cmath>
#include "CTriangle.h"
#include "Messages.h"
#include <sstream>

using namespace std;

CTriangle::CTriangle() = default;

CTriangle::CTriangle(CPoint &vertex1, CPoint &vertex2, CPoint &vertex3, uint32_t outlineColorTriangle, uint32_t fillColorTriangle):
	m_p1(vertex1),
	m_p2(vertex2),
	m_p3(vertex3),
	outlineColor(outlineColorTriangle),
	fillColor(fillColorTriangle)
{
}

CPoint CTriangle::GetVertex1()
{
	return m_p1;
}

CPoint CTriangle::GetVertex2()
{
	return m_p2;
}

CPoint CTriangle::GetVertex3()
{
	return m_p3;
}

uint32_t CTriangle::GetFillColor() const
{
	return fillColor;
}

uint32_t CTriangle::GetOutlineColor() const
{
	return outlineColor;
}

double CTriangle::GetPerimeter() const
{
	double side1 = sqrt(pow((m_p2.GetX() - m_p1.GetX()), 2) + pow((m_p2.GetY() - m_p1.GetY()), 2));
	double side2 = sqrt(pow((m_p3.GetX() - m_p1.GetX()), 2) + pow((m_p3.GetY() - m_p1.GetY()), 2));
	double side3 = sqrt(pow((m_p3.GetX() - m_p2.GetX()), 2) + pow((m_p3.GetY() - m_p2.GetY()), 2));
	double perimeter = side1 + side2 + side3;
	return perimeter;
}

double CTriangle::GetArea() const
{
	double side1 = sqrt(pow((m_p2.GetX() - m_p1.GetX()), 2) + pow((m_p2.GetY() - m_p1.GetY()), 2));
	double side2 = sqrt(pow((m_p3.GetX() - m_p1.GetX()), 2) + pow((m_p3.GetY() - m_p1.GetY()), 2));
	double side3 = sqrt(pow((m_p3.GetX() - m_p2.GetX()), 2) + pow((m_p3.GetY() - m_p2.GetY()), 2));
	double semi_perimeter = (side1 + side2 + side3) / 2;
	double square = sqrt(semi_perimeter * (semi_perimeter - side1) * (semi_perimeter - side2) * (semi_perimeter - side3));
	return square;
}

string CTriangle::ToString() const
{
	stringstream out;
	out.precision(2);
	out << TRIANGLE << endl;
	out << SQUARE << fixed << GetArea() << endl;
	out << PERIMETER << fixed << GetPerimeter() << endl;
	out << OUTLINE_COLOR << GetOutlineColor() << endl;
	out << FILL_COLOR << GetOutlineColor() << endl;
	out << X1_COORD << fixed << m_p1.GetX() << Y_COORD << fixed << m_p1.GetY() << endl;
	out << X2_COORD << fixed << m_p2.GetX() << Y_COORD << fixed << m_p2.GetY() << endl;
	out << X3_COORD << fixed << m_p3.GetX() << Y_COORD << fixed << m_p3.GetY() << endl;
	return out.str();
}