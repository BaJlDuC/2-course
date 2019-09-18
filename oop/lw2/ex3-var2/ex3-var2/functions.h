#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string INVALID_ARG = "������������ ����.\n������� translator.exe <���� �������>";
const string FILE_NOT_FOUND = "���� ������� �� ������. ���� ����� ������, ���� �� ������ ��������� �������� � ������� ������";
const string ENTER_TXT = "������� ��� ������� � ������� .txt";
const string FILE_FOUND = "���� ������� ������ � ������";
const string BEFORE_ENTER = ">";
const string WORD_NOT_FOUND = "������ ����� ����������� � �������. ������� ������� ������� ����� ��� ������ ������ ����� ��������������� ���";
const string WORD_IGNORED = "����� ���������������";
const string WORD_SAVED = "����� ���������";
const string OUT_OF_DICTIONARY = "� ������� ���� �������� ���������. ������� Y ��� ���������� ����� ������� ��� N ��� ������ ��� ����������";
const string CHANGES_SAVED = "\n�� ��������� ���������";
const string CHANGES_NOT_SAVED = "�� ����� ��� ���������� ��������� � �������";
const string UNCORRECT_EXIT = "������������ ����. ������� Y ��� ���������� ����� ������� ��� N ��� ������ ��� ����������";
const string FOR_EXIT = "��� ������ �� ��������� �������� ...";

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