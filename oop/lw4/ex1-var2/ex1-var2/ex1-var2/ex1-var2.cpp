#include "pch.h"
#include "CShapeHandler.h"
#include <vector>

int main()
{
	setlocale(LC_ALL, "rus");
	CShapeHandler ShapeHandler;
	ShapeHandler.PrintInfo();
	vector<unique_ptr<IShape>> shapes = ShapeHandler.CreateShapes();
	ShapeHandler.PrintShapeWithLargestArea(shapes);	
	ShapeHandler.PrintShapeWithSmallestPerimeter(shapes);
	return 0;
}