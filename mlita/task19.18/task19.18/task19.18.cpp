//Задание 19.18 | Садовин Владислав, ПС-22 | Microsoft Visual Studio |
/*19.18.Смена знаков(3)
Задан массив из N целых чисел(1 & lt; N ≤ 10 5) и натуральное число M(M ≤ N).Поменять знаки
ровно у M чисел так, чтобы сумма чисел стала минимальна.Найти полученную сумму.
Ввод.Первая строка файла INPUT.TXT содержит числа N и M.Во второй строки задаются N
целых чисел, не превышающих по модулю 10 6.Все числа в строке разделены пробелом.
Вывод в файл OUTPUT.TXT.В единственной строке выводится полученная сумма.
Пример
Ввод
3 2
2 10 - 3
Вывод
- 15 */

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
	int N = 0, M = 0, number = 0;
	ifstream inputFile("INPUT.txt");
	ofstream outputFile("OUTPUT.txt");

	inputFile >> N >> M;
	int *numbers = new int[N];
	for (int i = 0; i != N; i++)
	{
		inputFile >> number;
		numbers[i] = number;
	}
	qsort(numbers, N, sizeof(int), compareElements);

	///////////////////////////////////////////////logic
	for (int i = 0; i != M; i++)
	{
		numbers[N - 1 - i] = -numbers[N - 1 - i];
	}
	//////////////////////////////////////////////////////

	number = 0;
	for (int i = 0; i != N; i++)
	{
		number += numbers[i];
	}
	outputFile << number;
}
