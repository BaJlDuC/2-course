/* Садовин Владислав, ПС-22 | Microsoft Visual Studio |
11.1. Треугольник и точка (5)
В декартовой системе координат на плоскости заданы координаты вершин треугольника и еще
одной точки. Определить, принадлежит ли эта точка треугольнику.
Ввод из файла INPUT.TXT. В четырех строках находятся пары чисел - координаты точек.
Числа в первых трех строках - это координаты вершин треугольника, в четвертой строке -
координаты тестируемой точки.
Вывод в файл OUTPUT.TXT. Вывести In, если точка находится внутри треугольника, или Out -
если снаружи.
Ограничения: координаты вершин - целые числа, для любой точки выполняются следующие
условия: -10 9  ≤ x, y ≤ 10 9 .
Примеры
Ввод 1 Ввод 2 Ввод 3 Ввод 4
0 0 0 0 0 0 0 0
100 0 100 0 100 0 100 0
0 100 0 100 0 100 0 100
100 100 10 10 50 50 0 0
Вывод 1 Вывод 2 Вывод 3 Вывод 4
Out In In In
*/

#include "pch.h"
#include <fstream>

using namespace std;

int main()
{
	long long x1, y1, x2, y2, x3, y3, x0, y0;
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	inputFile >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x0 >> y0;

	long long squareOfMainTriangle = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2;

	long long squareOfTriangle1 = abs((x1 - x0)*(y2 - y1) - (x2 - x1)*(y1 - y0)) / 2;
	long long squareOfTriangle2 = abs((x2 - x0)*(y3 - y2) - (x3 - x2)*(y2 - y0)) / 2;
	long long squareOfTriangle3 = abs((x3 - x0)*(y1 - y3) - (x1 - x3)*(y3 - y0)) / 2;

	if ((squareOfTriangle1 + squareOfTriangle2 + squareOfTriangle3) == squareOfMainTriangle)
	{
		outputFile << "In" << endl;
	}
	else if (((x0 == x1) && (y0 == y1)) || ((x0 == x2) && (y0 == y2)) || ((x0 == x3) && (y0 == y3)))
	{
		outputFile << "In" << endl;
	}
	else
	{
		outputFile << "Out" << endl;
	}
}


