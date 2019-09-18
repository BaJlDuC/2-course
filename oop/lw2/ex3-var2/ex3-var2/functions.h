#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string INVALID_ARG = "Неправильный ввод.\nВведите translator.exe <файл словаря>";
const string FILE_NOT_FOUND = "Файл словаря не найден. Файл будет создан, если вы решите сохранить переводы с текущей сессии";
const string ENTER_TXT = "Введите имя словаря в формате .txt";
const string FILE_FOUND = "Файл словаря найден и открыт";
const string BEFORE_ENTER = ">";
const string WORD_NOT_FOUND = "Данное слово отсутствует в словаре. Введите перевод данного слова или пустую строку чтобы проигнорировать его";
const string WORD_IGNORED = "Слово проигнорировано";
const string WORD_SAVED = "Слово сохранено";
const string OUT_OF_DICTIONARY = "В словарь были занесены изменения. Нажмите Y для сохранения перед выходом или N для выхода без сохранения";
const string CHANGES_SAVED = "\nВы сохранили изменения";
const string CHANGES_NOT_SAVED = "Вы вышли без сохранения изменений в словаре";
const string UNCORRECT_EXIT = "Некорректный ввод. Нажмите Y для сохранения перед выходом или N для выхода без сохранения";
const string FOR_EXIT = "Для выхода из программы наберите ...";

bool checkDictionary(const string &dictionaryName)
{
	if (dictionaryName.substr(dictionaryName.size() - 4) != ".txt")
	{
		return false;
	}
	else
	{
		return true;
	}
}

void readDictionary(ifstream &dictionaryFile, string &dictionaryName, map<string, string> &translator, bool &error)
{
	string enWord;
	string ruWord;
	bool emptyFile = false;
	if (!dictionaryFile)
	{
		error = true;
		cout << FILE_NOT_FOUND << endl;
		if (!checkDictionary(dictionaryName))
		{
			cout << ENTER_TXT << endl;
			abort();
		}
	}
	while (!dictionaryFile.eof() && (emptyFile != true))
	{
		getline(dictionaryFile, enWord, '-');
		if (enWord.empty())
		{
			emptyFile = true;
		}

		if (emptyFile != true)
		{
			getline(dictionaryFile, ruWord);
     		translator[enWord] = ruWord;
		}
	}
}

void findTranslation(string &keyWord, string &ruWord, map<string, string> &translator, bool &madeChanges)
{
	map<string, string>::iterator it = translator.find(keyWord);
	if (it != translator.end())
	{
		cout << it->second << endl;
	}
	else
	{
		cout << WORD_NOT_FOUND << endl;
		cin.ignore(0, '\n');
		getline(cin, ruWord);
		if (ruWord.empty())
		{
			cout << WORD_IGNORED << endl;
			madeChanges = false;
		}
		else
		{
			translator[keyWord] = ruWord;
			cout << WORD_SAVED << endl;
			madeChanges = true;
		}
	}
}

void saveChanges(char &exitButton, string &dictionaryName, map<string, string> &translator, bool &madeChanges)
{
	if (madeChanges == true)
	{
		cout << OUT_OF_DICTIONARY << endl;

		while ((exitButton != 'N') && (exitButton != 'Y'))
		{
			cin >> exitButton;
			switch (exitButton)
			{
			case 'Y':
			{
				ofstream dictionaryFile(dictionaryName.c_str());
				map<string, string>::iterator it = translator.begin();
				for (unsigned int i = 0; i <= (translator.size() - 1); it++, i++)
				{
					if ((i + 1) == translator.size())
					{
						dictionaryFile << it->first << "-" << it->second;
					}
					else
					{
						dictionaryFile << it->first << "-" << it->second << endl;
					}
				}
				cout << CHANGES_SAVED << endl;
			}
					break;
			case 'N':
					cout << CHANGES_NOT_SAVED << endl;
					break;
			default:
					cout << UNCORRECT_EXIT << endl;
					break;
			}
		}
	}
}