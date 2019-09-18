#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

using namespace std;

class CRectangle : public ISolidShape
{
protected:
	CPoint leftTop, rightBottom;
	//double height, width, perimeter, square;
	uint32_t fillColor, outlineColor;
public:
	CRectangle();
	CRectangle(CPoint &leftTopRectangle, CPoint &rightBottomRectangle, uint32_t outlineColorRectangle, uint32_t fillColorRectangle);

	double GetArea() const override;
	double GetPerimeter() const override;
	string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;
	CPoint GetLeftTop();
	CPoint GetRightBottom();
	double GetWidth() const;
	double GetHeight() const;
};