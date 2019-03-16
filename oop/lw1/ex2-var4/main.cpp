#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

const string INVALID_ARG = "Invalid arguments\nEnter: dec2bin.exe <decimalNumber>";
const string UNCORRECT_ARG = "Uncorrect argument\nEnter only integer number from (0 <= num < (2^31)-1)";
const string OUT_NULL = "0";
const int NUM_NULL = 0;

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
    if (decimalString == "0")
    {
        cout << OUT_NULL;
        return 0;
    }
    size_t stoppedAt;
    int decimalNumber = 0;

    try
    {
        decimalNumber = stoi(decimalString, &stoppedAt);
    }

    catch (invalid_argument)
    {
        cout << UNCORRECT_ARG << endl;
        return 1;
    }

    catch (out_of_range)
    {
        cout << UNCORRECT_ARG << endl;
        return 1;
    }

    if ((decimalNumber < NUM_NULL) || (stoppedAt != decimalString.size()))
    {
        cout << UNCORRECT_ARG << endl;
        return 1;
    }

    printBin(decimalNumber);
    return 0;
}