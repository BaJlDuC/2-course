// Задание 19.4 | Садовин Владислав, ПС-22 | Microsoft Visual Studio |
/*19.4.Спираль(3).Расположить N 2 чисел от 1 до N 2 в квадрате по спирали.
Ввод.В единственной строке файла INPUT.TXT задано число N(1 ≤ N ≤ 50).
Вывод.Выходной файл OUTPUT.TXT содержит N 2 чисел по N чисел по спирали.
Пример
Ввод
4
Вывод
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7*/

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;
const int STOP_NUMBER = 99;

int main()
{
	ifstream inputFile("INPUT.txt");
	ofstream outputFile("OUTPUT.txt");

	int N, maxNum;

	inputFile >> N;
	maxNum = pow(N, 2);
	int count = 0;
	int **spiral = new int *[N];
	for (int i = 0; i != N; i++)
	{
		spiral[i] = new int[N];
	}
	for (int j = 0; j != STOP_NUMBER + 1; j++)
	{
		for (int i = j; i != N - j; i++) //вправо
		{
			count++;
			spiral[j][i] = count;
		}
		if (count == maxNum)
		{
			j = STOP_NUMBER;
		}

		if (j != STOP_NUMBER)
		{
			for (int i = j + 1; i != N - j; i++) //вниз
			{
				count++;
				spiral[i][N - j - 1] = count;
			}
		}
	    if (count == maxNum)
		{
			j = STOP_NUMBER;
		}

		if (j != STOP_NUMBER)
		{
			for (int i = N - j - 1; i != j; i--) //влево
			{
				count++;
				spiral[N - j - 1][i - 1] = count;
			}
		}
		if (count == maxNum)
		{
			j = STOP_NUMBER;
		}

		if (j != STOP_NUMBER)
		{
			for (int i = N - j - 2; i != j; i--) // вверх
			{
				count++;
				spiral[i][j] = count;
			}
		}
		if (count == maxNum)
		{
			j = STOP_NUMBER;
		}
		
	}

	for (int j = 0; j != N; j++) //вывод
	{
		for (int i = 0; i != N; i++)
		{
			outputFile << spiral[j][i] << ' ';
		}
		outputFile << endl;
	}
}