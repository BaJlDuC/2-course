#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

const string BIG_NUMBER = "Very big number (number > (2^31)-1)";
const string INVALID_ARG = "Invalid arguments\nEnter: dec2bin.exe <decimalNumber>";
const string UNCORRECT_ARG = "Uncorrect argument\nEnter only integer number";
const string OUT_NULL = "0";

bool checkCorrect(char number)
{
    if ((number >= '0') && (number <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printBin(unsigned dec)
{
    if (dec)
    {
        printBin(dec >> 1);
        cout << (dec & 1);
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << INVALID_ARG << endl;
        return 1;
    }

    string decimalString(argv[1]);
    unsigned int decimalNumber = 0;
    int bigInt = pow(2, 31) - 1;
    stringstream convertString;
    convertString << decimalString;
    convertString >> decimalNumber;

    for (int i = 0; i < decimalString.size(); i++)
    {
        if (!checkCorrect(decimalString[i]))
        {
            cout << UNCORRECT_ARG << endl;
            return 1;
        }
    }
    if (decimalString == "0")
    {
        cout << OUT_NULL << endl;
        return 0;
    }

    if ((decimalNumber) > bigInt)
    {
        cout << BIG_NUMBER << endl;
        return 1;
    }

    printBin(decimalNumber);
    return 0;
}