//Задача 19.2 | Садовин Владислав, ПС-32(22) | Microsoft Visual Studio |
/* 19.2. Домино (3)
Найти количество вариантов покрытия прямоугольника 2×N прямоугольниками 2×1.
Покрытия, которые преобразуются друг в друга симметриями, считать различными.
Ввод.В единственной строке входного файла INPUT.TXT задано значение N(1 ≤ N ≤ 20).
Вывод.В единственной строке выходного файла OUTPUT.TXT должно содержаться
количество вариантов покрытия прямоугольника.
Пример
Ввод
5
Вывод
8*/
#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int N = 0 , result = 0, previous = 2, previousMore = 1;

	

	ifstream inputFile("INPUT.txt");
	ofstream outputFile("OUTPUT.txt");

	inputFile >> N;

	if (N == 1)
	{
		result = 1;
		outputFile << result << endl;
	}
	else if (N == 2)
	{
		result = 2;
		outputFile << result << endl;
	}
	else
	{
		for (int i = 2; i != N; i++)
		{
			result = previous + previousMore;
			previousMore = previous;
			previous = result;
		}
		outputFile << result << endl;
	}
}