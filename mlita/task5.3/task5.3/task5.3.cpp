// Задача 5.3 | Садовин Владислав, ПС-22(32) | Microsoft Visual Studio |
/*5.3.Число цифр(5)
Найти суммарное число цифр во всех целых числах от M до N включительно.
Ввод из файла INPUT.TXT.В единственной строке находятся целые числа M и N(1 ≤ M ≤ N ≤ 10 15).
Вывод в файл OUTPUT.TXT.В единственную строку вывести суммарное число цифр.
Примеры
Ввод 1 Ввод 2
1 2      2 11
Вывод 1 Вывод 2
2        12*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string numberOnString = "";
	vector<unsigned long long> numbers;
	unsigned long long int M = 0, N = 0, digits = 0;
	int digitsOnM = 0, digitsOnN = 0;

	ifstream inputFile("INPUT.txt");
	ofstream outputFile("OUTPUT.txt");

	inputFile >> M >> N;

	for (unsigned long long i = M; i != 0; i /= 10)
	{
		digitsOnM++;
	}
	for (unsigned long long i = N; i != 0; i /= 10)
	{
		digitsOnN++;
	}


	if (digitsOnM == digitsOnN)
	{
		digits = (((pow(10, digitsOnM) - M) * digitsOnM) - ((pow(10, digitsOnM) - N) * digitsOnM) + digitsOnM);
		outputFile << digits << endl;
		return 0;
	}
	for (unsigned long long int i = digitsOnM; i != digitsOnN + 1; i++)
	{
		if (i != digitsOnN)
		{
			if (i == digitsOnM)
			{
				digits += (pow(10, i) - M) * i;
			}
			else
			{
				digits += (pow(10, i) - pow(10, i - 1)) * i;
			}
		}
		else
		{
       		unsigned long long int testResult = ((pow(10, i) - pow(10, i - 1)) * i) - ((pow(10, i) - N) * i) + i;
			//digits += (((pow(10, i) - pow(10, i - 1)) * i) - ((pow(10, i) - N) * i) + i); // искомый вариант
			digits = digits + testResult;
		}
	}
	outputFile << digits << endl;
}