#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <windows.h>
#include "functions.h" 

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "RUSSIAN");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	map<string, string> translator;
	string enWord;
	string ruWord;
	string keyWord;
	char exitButton;
	bool madeChanges;
	bool error;

	if (argc != 2)
	{
		cout << INVALID_ARG << endl;
		return 1;
	}

	string dictionaryName(argv[1]);
	ifstream dictionaryFile(dictionaryName.c_str());
	readDictionary(dictionaryFile, dictionaryName, translator, error);
	cout << FOR_EXIT << endl;

	while (keyWord != "...")
	{
		cout << BEFORE_ENTER;
		cin.ignore(0, '\n');
		getline(cin, keyWord);
		if (keyWord != "...")
		{
			findTranslation(keyWord, ruWord, translator, madeChanges);
		}
		else
		{
			saveChanges(exitButton, dictionaryName, translator, madeChanges);
		}
	}
}