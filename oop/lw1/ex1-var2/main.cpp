#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string INVALID_IN = "Invalid arguments\nEnter: compare.exe <file1> <file2>";
const string NOT_FOUND = " not found";
const string DIFFERENT = "File is different. Line number is ";
const string EQUAL = "Files are equal";

bool CompareFiles(ifstream &file1, ifstream &file2, int &numberStr)
{
    string s1, s2;

    while (!file1.eof() || !file2.eof())
    {
        if ((file1.eof() && !file2.eof()))
        {
            numberStr++;
            return false;
        }
        if ((!file1.eof() && file2.eof()))
        {
            numberStr++;
            return false;
        }
        getline(file1, s1);
        getline(file2, s2);
        numberStr++;
        if (s1 != s2)
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        cout << INVALID_IN;
        return 1;
    }

    ifstream file1(argv[1]), file2(argv[2]);

    if (!file1.is_open())
    {
        cout << argv[1] << NOT_FOUND << endl;
        return 1;
    }

    if (!file2.is_open())
    {
        cout << argv[2] << NOT_FOUND << endl;
        return 1;
    }

    int numberStr = 0;

    if (!CompareFiles(file1, file2, numberStr))
    {
        cout << DIFFERENT << numberStr << endl;
        return 1;
    }

    cout << EQUAL << endl;
    return 0;
}