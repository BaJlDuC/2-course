#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <windows.h>

using namespace std;

const string INVALID_ARG = "Invalid arguments";
const string FILE_NOT_FOUND = "File is not found";
const string ENTER_TXT = "Please enter dictionary name in .txt format";
const string FILE_CREATED = "Created dictionary file ";
const string FILE_FOUND = "Dictionary file is found and opened";
const string BEFORE_ENTER = ">";
const string WORD_NOT_FOUND = "Данное слово отсутствует в словаре. Введите перевод данного слова или пустую строку чтобы проигнорировать его";
const string WORD_IGNORED = "Слово проигнорировано";
const string WORD_SAVED = "Слово сохранено";
const string OUT_OF_DICTIONARY = "В словарь были занесены изменения. Нажмите Y для сохранения перед выходом или N для выхода без сохранения";
const string CHANGES_SAVED = "Вы сохранили изменения";
const string CHANGES_NOT_SAVED = "Вы вышли без сохранения изменений в словаре";
const string UNCORRECT_EXIT = "Некорректный ввод. Нажмите Y для сохранения перед выходом или N для выхода без сохранения";

bool checkDictionary(string dictionaryName)
{
    for (int i = 1; i <= 4; i++)
    {
        if (((i == 1) && (dictionaryName[dictionaryName.size() - 1]) != 't'))
        {
            return false;
        }
        if (((i == 2) && (dictionaryName[dictionaryName.size() - 2]) != 'x'))
        {
            return false;
        }
        if (((i == 3) && (dictionaryName[dictionaryName.size() - 3]) != 't'))
        {
            return false;
        }
        if (((i == 4) && (dictionaryName[dictionaryName.size() - 4]) != '.'))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    // setlocale(LC_ALL, "RUSSIAN");
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);

    map<string, string> translator;
    string enWord;
    string ruWord;
    string keyWord;
    string exitButton;
    bool dictionaryCreated;
    bool madeChanges;

    if (argc != 2)
    {
        cout << INVALID_ARG << endl;
        return 1;
    }

    string dictionaryName(argv[1]);
    ifstream dictionaryFile(dictionaryName.c_str());
    if (!dictionaryFile)
    {
        cout << FILE_NOT_FOUND << endl;
        if (!checkDictionary(dictionaryName))
        {
            cout << ENTER_TXT << endl;
            return 1;
        }
        ofstream dictionaryFile(dictionaryName.c_str());
        cout << FILE_CREATED << dictionaryName << endl;
        dictionaryCreated = true;
    }
    else
    {
        cout << FILE_FOUND << endl;
        dictionaryCreated = false;
    }

    if (dictionaryCreated == false)
    {
        while (!dictionaryFile.eof())
        {
            getline(dictionaryFile, enWord, '-');
            if (!enWord.empty())
            {
                cout << enWord << " - key, ";
            }
            else
            {
                cout << "English word(key) is empty!" << endl;
            }
            getline(dictionaryFile, ruWord);
            if (!ruWord.empty())
            {
                cout << ruWord << " - value" << endl;
                translator[enWord] = ruWord;
            }
            else
            {
                cout << "Russian word(value) is empty!" << endl;
            }
        }
    }

    dictionaryFile.close();
    while (keyWord != "...")
    {
        cout << BEFORE_ENTER;
        cin.ignore(0, '\n');
        getline(cin, keyWord);
        if (keyWord != "...")
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
        else
        {
            cout << OUT_OF_DICTIONARY << endl;

            while ((exitButton != "N") && (exitButton != "Y"))
            {
                cin >> exitButton;
                if (exitButton == "Y")
                {
                    ofstream dictionaryFile(dictionaryName.c_str());
                    map<string, string>::iterator it = translator.begin();
                    cout << translator.size() << endl;
                    for (int i = 0; i <= translator.size(); it++, i++)
                    {
                        if ((i + 1) == translator.size())
                        {
                            dictionaryFile << it->first << "-" << it->second;
                            cout << it->first << "-" << it->second;
                        }
                        else
                        {
                            dictionaryFile << it->first << "-" << it->second << endl;
                            cout << it->first << "-" << it->second << endl;
                        }
                    }
                    cout << CHANGES_SAVED << endl;
                }
                else
                {
                    if (exitButton == "N")
                    {
                        cout << CHANGES_NOT_SAVED << endl;
                    }
                    else
                    {
                        cout << UNCORRECT_EXIT << endl;
                    }
                }
            }
        }
    }
}