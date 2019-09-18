//| Задание 19.20 | Садовин Владислав, ПС-22 | Microsoft Visual Studio |
/*19.20.Кольца(3)
Имеется заготовка из жести в виде круга.Требуется определить, можно ли из нее вырезать два
кольца заданных размеров.Кольцо представляет собой плоскую фигуру, ограниченную двумя
концентрическими окружностями.
Ввод из файла INPUT.TXT.Первая строка содержит число тестовых блоков L(L ≤ 10).Каждый
тестовый блок состоит из одной строки.Каждая строка содержит пять целых чисел через пробел :

A, a, B, b, R.Здесь A и a – внешний и внутренний радиусы первого кольца(a &lt; A), B и b - внешний
и внутренний радиусы второго кольца(b &lt; B), R – радиус круга.Все числа не превышают 1000.
Вывод в файл OUTPUT.TXT.Для каждого тестового блока выводится строка со значением Yes
или No – можно или нет вырезать заданные кольца.
Пример
Ввод
2
2 1 5 3 6
5 2 3 1 6
Вывод
Yes
No
*/
#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inputFile("INPUT.txt");
	ofstream outputFile("OUTPUT.txt");

	int A = 0, a = 0, B = 0, b = 0, R = 0, numberOfTests = 0;
	inputFile >> numberOfTests;

	for (int count = 0; count != numberOfTests; count++)
	{
		inputFile >> A >> a >> B >> b >> R;
		if ((A > R) || (a > R) || (B > R) || (b > R))
		{
			outputFile << "No" << endl;
		} 
		else if ((A <= a) || (B <= b))
		{
			outputFile << "No" << endl;
		}
		else if ((a < B) && (A > B) && ((A + B) > R))
		{
			outputFile << "No" << endl;
		}
		/////////////////
		else if ((B > A) && (a > b) && ((A + B) > R))
		{
			outputFile << "No" << endl;
		}
		/////////////////
		else
		{
			outputFile << "Yes" << endl;
		}
	}
}
