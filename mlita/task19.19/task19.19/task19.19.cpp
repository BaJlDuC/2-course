//Задание 19.19 | Садовин Владислав, ПС-22 | Microsoft Visual Studio |
/*19.19.Лестница(3)
По широкой лестнице с разной скоростью спускаются N человек.В начальный момент они
находятся на разных ступенях.Обгоны запрещены, но если человек A догнал человека B, который
идет с более низкой скоростью, то до конца лестницы человек A идет вместе с человеком B.При
этом на одной ступени лестницы может помещаться сколько угодно человек.Требуется
рассчитать время, за которое каждый человек спустится по лестнице.
Ввод из файла INPUT.TXT.В первой строке записано число N(1 ≤ N ≤1000).В следующих N
строках заданы пары целых чисел t i, w i(1 ≤ t i, w i ≤ 1000) – время прохода одной ступени в секундах
и количество ступеней до конца лестницы.Изначально всем людям остается идти различное число
ступеней.
Вывод в файл OUTPUT.TXT - N строк.В i - ой строке выводится время в секундах, через
которое i - ый человек сойдет с лестницы.
Примеры
Ввод 1 Ввод 2
3 3
2 10 2 11
3 11 3 12
1 12 5 4
Вывод 1 Вывод 2
20 22
33 36
33 20*/
#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int compareElements(const void *element1, const void *element2)
{
	return (*(int*)element1 - *(int*)element2);
}

int main()
{
	ifstream inputFile("INPUT.txt");
	ofstream outputFile("OUTPUT.txt");

	int N = 0, t = 0, S = 0;
	bool readed;

	inputFile >> N;
	int* timeForEachPeople = new int[N];
	int* stairs = new int[N];
	int* stairsWithTime = new int[N];

	for (int i = 0; i != N; i++) 
	{
		inputFile >> t >> S;
		timeForEachPeople[i] = t * S;
		stairs[i] = S;
		
	}

	qsort(stairs, N, sizeof(int), compareElements);
	inputFile.seekg(1, ios::beg);

	for (int i = 0; i != N; i++)
	{
		readed = false;
		inputFile >> t >> S;
		for (int j = 0; j != N; j++)
		{
			if ((stairs[j] == S) && (readed == false))
			{
				stairsWithTime[j] = S * t; //was stairs
				readed = true;
			}
		}
	}

	for (int i = 0; i != N; i++)
	{
			if (stairsWithTime[i] > stairsWithTime[i + 1])
			{
				for (int k = 0; k != N; k++)
				{
					if (timeForEachPeople[k] == stairsWithTime[i]) // 
					{
						for (int m = k + 1; m != N; m++) //was i + 1
						{
							if (timeForEachPeople[m] == stairsWithTime[i + 1]) // 
							{
								timeForEachPeople[m] = timeForEachPeople[k]; // was j
							}
						}
					}
				}
				stairsWithTime[i + 1] = stairsWithTime[i];
			}
	}

	for (int i = 0; i != N; i++)
	{
		outputFile << timeForEachPeople[i] << endl;
	}
}