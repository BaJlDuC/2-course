#pragma once
#include "CPoint.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include <vector>
#include <algorithm>
#include <cmath>

class CShapeHandler
{
public:
	unique_ptr<CLineSegment> CreateLineSegment(istream &inStrm);
	unique_ptr<CTriangle> CreateTriangle(istream &inStrm);
	unique_ptr<CRectangle> CreateRectangle(istream &inStrm);
	unique_ptr<CCircle> CreateCircle(istream &inStrm);
	unique_ptr<IShape> CreateShape(const string &inStr);
	vector<unique_ptr<IShape>> CreateShapes();
	void PrintShapeWithLargestArea(const vector<unique_ptr<IShape>> &shapes);
	void PrintShapeWithSmallestPerimeter(const vector<unique_ptr<IShape>> &shapes);
	void PrintInfo();
    //bool PerimeterCompare(const unique_ptr<IShape> &shape1, const unique_ptr<IShape> &shape2);
	//bool AreaCompare(const unique_ptr<IShape> &shape1, const unique_ptr<IShape> &shape2);
};