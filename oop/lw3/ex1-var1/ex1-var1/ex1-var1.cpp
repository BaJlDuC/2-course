#include "pch.h"
#include <iostream>
#include <string>
#include "CTVSet.h"
#include "СmdHandler.h"

using namespace std;

int main()
{   
	setlocale(LC_ALL, "rus");

	cout << WELCOME << endl;
	CmdHandler cmdHandler;
	CTVSet TV;
	cmdHandler.commandProcessing(TV);
}