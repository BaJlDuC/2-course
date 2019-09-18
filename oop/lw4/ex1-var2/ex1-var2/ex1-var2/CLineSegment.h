#pragma once
#include "CPoint.h"
#include "IShape.h"
#include <stdint.h>

using namespace std;

class CLineSegment : public IShape
{
protected:
	CPoint startPoint, endPoint;
	uint32_t outlineColor;
public:
	CLineSegment();
	CLineSegment(CPoint &startLine, CPoint &endLine, uint32_t outlineColorLine);

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	double GetArea() const override;
	double GetPerimeter() const override;
	double GetLength() const;
	uint32_t GetOutlineColor() const override;
	string ToString() const override;

};
