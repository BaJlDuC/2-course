#pragma once

class CPoint
{
protected:
	double m_x, m_y;
public:
	CPoint();
	CPoint(double x, double y);

	double GetX() const;
	double GetY() const;
};