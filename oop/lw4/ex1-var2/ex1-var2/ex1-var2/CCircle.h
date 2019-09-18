#pragma once
#include "CPoint.h"
#include "ISolidShape.h"
#include <stdint.h>

using namespace std;

class CCircle : public ISolidShape
{
protected:
	CPoint centerPoint;
	double radius;
	uint32_t fillColor, outlineColor;
public:
	CCircle();
	CCircle(CPoint &centerPointCoords, double circleRadius, uint32_t outlineColorCircle, uint32_t fillColorCircle);

	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetCenter();
	double GetRadius() const;
	string ToString() const override;
	uint32_t GetFillColor() const override;
	uint32_t GetOutlineColor() const override;
};
