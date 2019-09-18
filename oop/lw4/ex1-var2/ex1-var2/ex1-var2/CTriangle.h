#pragma once
#include <stdint.h>
#include <string>
#include "CPoint.h"
#include "ISolidShape.h"

using namespace std;

class CTriangle : public ISolidShape
{
protected:
	CPoint m_p1, m_p2, m_p3;
	//double side1, side2, side3, perimeter, semi_perimeter, square;
	uint32_t outlineColor, fillColor;

public:
	CTriangle();
	CTriangle(CPoint &vertex1, CPoint &vertex2, CPoint &vertex3, uint32_t outlineColorTriangle, uint32_t fillColorTriangle);

	CPoint GetVertex1();
	CPoint GetVertex2();
	CPoint GetVertex3();
	//bool CheckCorrectVertex();
	uint32_t GetFillColor() const override;
	uint32_t GetOutlineColor() const override;
	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
};