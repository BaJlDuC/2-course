// | Задача 19.7 | Садовин Владислав, ПС-22 | Microsoft Visual Studio |
/*19.7.Последняя цифра(2)
Найти последнюю цифру числа a n, где a и n – натуральные числа(1 ≤ a, n ≤ 10 4).
Ввод.В единственной строке файла INPUT.TXT заданы числа a и n.
Вывод.В файл OUTPUT.TXT вывести единственное требуемое число.
Пример
Ввод
7 2
Вывод
9*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inputFile("INPUT.txt");
	ofstream outputFile("OUTPUT.txt");

	long long a = 0, n = 0, modifiedA = 0;
	inputFile >> a >> n;
	modifiedA = a;
	if (n == 0)
	{
		outputFile << 1 << endl;
	}
	else if (n == 1)
	{
		modifiedA %= 10;
		outputFile << modifiedA << endl;
	}
	else
	{
		for (int i = 1; i != n; i++)
		{
			modifiedA *= a;
			modifiedA %= 10;
		}
		outputFile << modifiedA << endl;
	}
}