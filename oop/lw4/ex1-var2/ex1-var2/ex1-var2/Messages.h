#pragma once
#include <string>

using namespace std;

const string TRIANGLE = "---triangle---";
const string CIRCLE = "---circle---";
const string LINE_SEGMENT = "---lineSegment---";
const string RECTANGLE = "---rectangle---";

//triangle
const string SQUARE = "Square = ";
const string PERIMETER = "Perimeter = ";
const string OUTLINE_COLOR = "Outline color: ";
const string FILL_COLOR = "Fill color: ";
const string X1_COORD = "Vertex1 coords: X = ";
const string X2_COORD = "Vertex2 coords: X = ";
const string X3_COORD = "Vertex3 coords: X = ";
const string Y_COORD = ", Y = ";

//circle
const string RADIUS = "Radius = ";
const string CENTER_X = "Center coords: X = ";

//lineSegment
const string START_X = "Start point coords: X = ";
const string END_X = "End point coords: X = ";
const string LENGTH = "Length = ";

//rectangle
const string LEFT_TOP_X = "Left top coords : X = ";
const string RIGHT_BOTTOM_X = "Right bottom coords: X = ";
const string RECTANGLE_WIDTH = "Width = ";
const string RECTANGLE_HEIGHT = "Height = ";

const string INVALID_INPUT = "Invalid input string";
const string LINE_SEGMENT_READED = "LineSegment is readed";
const string FIGURE_READED = "Figure is readed";
const string LINE_SEGMENT_FOR_READING = "lineSegment";
const string TRIANGLE_FOR_READING = "triangle";
const string CIRCLE_FOR_READING = "circle";
const string RECTANGLE_FOR_READING = "rectangle";
const string LARGEST_SQUARE_SHAPE = "Shape whith largest square:\n";
const string SMALLEST_PERIMETER_SHAPE = "Shape whith smallest perimeter:\n";
const string INFO = "Правильный ввод: вводим одну фигуру и жмем Enter, следующую и Enter и т. д. Фигуры: ";
const string INFO_RECTANGLE = " для прям-ка вводим коор-ты 2 точек (верхний левый и нижний правый, и цвета): rectangle x1 y1 x2 y2 outlineColor fillColor";
const string INFO_TRIANGLE = " для треугольника вводим коор-ты 3 вершин, также цвета: triangle x1 y1 x2 y2 x3 y3 outlineColor fillColor";
const string INFO_CIRCLE = " для круга вводим коор-ты центра, радиус и цвета: circle x1 y1 radius outlineColor fillColor";
const string INFO_LINE_SEGMENT = " для отрезка вводима коор-ты начала и конца, также цвет: lineSegment x1 y1 x2 y2 outlineColor";