//| Задание 19.16 | Садовин Владислав, ПС-22 | Microsoft Visual Studio |
/*19.16.Простые числа(3)
Найти сумму простых чисел, расположенных между N и K(0 & lt; N ≤ K ≤ 4×10 6), включая эти
числа.
Ввод.В первой строке файла INPUT.TXT содержатся через пробел натуральные числа N и K.
Вывод.Вывести в файл OUTPUT.TXT одно число - сумму простых чисел, расположенных
между N и K.
Пример
Ввод
1 5
Вывод
10*/

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inputFile("INPUT.txt");
	ofstream outputFile("OUTPUT.txt");

	int N, K, index = 0, del = 0;
	long long sum = 0;
	inputFile >> N >> K;
	int *numbers = new int[K];
    
	for (int i = 0; i != K + 1; i++)
	{
		numbers[i] = i;
	}
	for (int i = 2; pow(i, 2) <= K; i++)
	{
		del = pow(i, 2);
		while (del <= K)
		{
			numbers[del] = 0;
			del += i;
		}
	}
	numbers[1] = 0;
	for (int i = N; i != K + 1; i++)
	{
		sum += numbers[i];
	}
	outputFile << sum << endl;
}
