// testsCatch2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

//#include "pch.h"
//#include <iostream>
//#pragma comment(lib, "opengl32.lib") 
//#pragma comment(lib, "glu32.lib") 
//#pragma comment(lib, "glaux.lib")
#define CATCH_CONFIG_MAIN
#include <..\..\catch2\catch.hpp>
#include <..\ex3-var2\functions.h>


TEST_CASE("Open dictionary tests")
{
	CHECK(checkDictionary("testingword.eze") == false);
	CHECK(checkDictionary("dictionarywithoutformat") == false);
	CHECK(checkDictionary("dictionary.txt") == true);
}

TEST_CASE("Read translations")
{
	setlocale(LC_ALL, "RUSSIAN");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool testOpen = false;
	map <string, string> dictionaryMap;
	map <string, string> translator;
	bool error = false;
	ifstream dictionary("../ex3-var2/newDictionary.txt");
	string fileName = "dicrionary.txt";
	if (dictionary)
	{
		testOpen = true;
	}
	CHECK(testOpen == true);
	readDictionary(dictionary, fileName, translator, error);
	dictionaryMap = { {"The Red Square", "Красная Площадь"}, {"table", "стол"}};
	CHECK(dictionaryMap.size() == translator.size());
}

