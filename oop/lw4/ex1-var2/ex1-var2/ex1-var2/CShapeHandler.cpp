#include <iostream>
#include <sstream>
#include "CShapeHandler.h"
#include "Messages.h"

using namespace std;

unique_ptr<CLineSegment> CShapeHandler::CreateLineSegment(istream &inStrm)
{
	double x1, y1, x2, y2;
	uint32_t outlineColor;
	inStrm >> x1 >> y1 >> x2 >> y2 >> hex >> outlineColor;
	if (!inStrm)
	{
		throw runtime_error(INVALID_INPUT);
	}
	char ch = ' ';
	inStrm >> ch;
	if (ch != ' ')
	{
		throw runtime_error(INVALID_INPUT);
	}
	else
	{
		cout << LINE_SEGMENT_READED << endl;
	}
	CPoint startPoint(x1, y1);
	CPoint endPoint(x2, y2);
	return make_unique<CLineSegment>(startPoint, endPoint, outlineColor);
}

unique_ptr<CTriangle> CShapeHandler::CreateTriangle(istream &inStrm)
{
	double x1, y1, x2, y2, x3, y3;
	uint32_t outlineColor, fillColor;
	inStrm >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> hex >> outlineColor >> fillColor;
	if (!inStrm)
	{
		throw runtime_error(INVALID_INPUT);
	}
	char ch = ' ';
	inStrm >> ch;
	if (ch != ' ')
	{
		throw runtime_error(INVALID_INPUT);
	}
	else
	{
		cout << FIGURE_READED << endl;
	}
	CPoint vertex1(x1, y1);
	CPoint vertex2(x2, y2);
	CPoint vertex3(x3, y3);
	return make_unique<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
}

unique_ptr<CRectangle> CShapeHandler::CreateRectangle(istream &inStrm)
{
	double x1, y1, x2, y2;
	uint32_t outlineColor, fillColor;
	inStrm >> x1 >> y1 >> x2 >> y2 >> hex >> outlineColor >> fillColor;
	if (!inStrm)
	{
		throw runtime_error(INVALID_INPUT);
	}
	char ch = ' ';
	inStrm >> ch;
	if (ch != ' ')
	{
		throw runtime_error(INVALID_INPUT);
	}
	else
	{
		cout << FIGURE_READED << endl;
	}
	CPoint leftTop(x1, y1);
	CPoint rightBottom(x2, y2);
	return make_unique<CRectangle>(leftTop, rightBottom, outlineColor, fillColor);
}

unique_ptr<CCircle> CShapeHandler::CreateCircle(istream &inStrm)
{
	double x, y, radius;
	uint32_t outlineColor, fillColor;
	inStrm >> x >> y >> radius >> hex >> outlineColor >> fillColor;
	if (!inStrm)
	{
		throw runtime_error(INVALID_INPUT);
	}
	char ch = ' ';
	inStrm >> ch;
	if (ch != ' ')
	{
		throw runtime_error(INVALID_INPUT);
	}
	else
	{
		cout << FIGURE_READED << endl;
	}
	CPoint center(x, y);
	return make_unique<CCircle>(center, radius, outlineColor, fillColor);
}

unique_ptr<IShape> CShapeHandler::CreateShape(const string &inStr)
{
	string name;
	istringstream inStrm(inStr);
	inStrm >> name;
	if (name == LINE_SEGMENT_FOR_READING)
	{
		return CreateLineSegment(inStrm);
	}
	else if (name == TRIANGLE_FOR_READING)
	{
		return CreateTriangle(inStrm);
	}
	else if (name == RECTANGLE_FOR_READING)
	{
		return CreateRectangle(inStrm);
	}
	else if (name == CIRCLE_FOR_READING)
	{
		return CreateCircle(inStrm);
	}
	else
	{
		throw runtime_error(INVALID_INPUT);
	}
}

vector<unique_ptr<IShape>> CShapeHandler::CreateShapes()
{
	vector<unique_ptr<IShape>> shapes;
	string inStr;
	while (getline(cin, inStr))
	{
		try
		{
			shapes.push_back(CreateShape(inStr));
		}
		catch (const runtime_error &err)
		{
			cout << err.what() << endl;
		}
	}
	return shapes;
}

bool PerimeterCompare(const unique_ptr<IShape> &shape1, const unique_ptr<IShape> &shape2)
{
	return (shape1->GetPerimeter() < shape2->GetPerimeter());
}

bool AreaCompare(const unique_ptr<IShape> &shape1, const unique_ptr<IShape> &shape2)
{
	return (shape1->GetArea() < shape2->GetArea());
}

void CShapeHandler::PrintShapeWithLargestArea(const vector<unique_ptr<IShape>> &shapes)
{
	if (shapes.size() > 0)
	{
		auto result = max_element(shapes.begin(), shapes.end(), AreaCompare);
		cout << LARGEST_SQUARE_SHAPE << shapes[distance(shapes.begin(), result)]->ToString() << endl;

	}
}

void CShapeHandler::PrintShapeWithSmallestPerimeter(const vector<unique_ptr<IShape>> &shapes)
{
	if (shapes.size() > 0)
	{
		auto result = min_element(shapes.begin(), shapes.end(), PerimeterCompare);
		cout << SMALLEST_PERIMETER_SHAPE << shapes[distance(shapes.begin(), result)]->ToString() << endl;
	}
}

void CShapeHandler::PrintInfo()
{
	cout << INFO << endl;
	cout << INFO_RECTANGLE << endl;
	cout << INFO_TRIANGLE << endl;
	cout << INFO_CIRCLE << endl;
	cout << INFO_LINE_SEGMENT << endl;
}