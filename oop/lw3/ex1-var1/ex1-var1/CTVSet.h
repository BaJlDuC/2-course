#pragma once
#include <string>
#include <iostream>

using namespace std;

const string TV_TURNED_ON = "Вы включили телевизор";
const string TV_TURNED_ON_NOW = "Телевизор уже включен";
const string TV_TURNED_OFF = "Вы выключили телевизор";
const string TV_TURNED_OFF_NOW = "Телевизор уже выключен";
const string TV_YOU_SWITCH = "Вы переключили на ";
const string TV_NUMBER_OF_CHANNEL = "-й канал";
const string TV_OFF_IMPOSSIBLE_SWITCHING = "Телевизор выключен, переключение канала невозможно";
const string TV_OFF_INFO = "Телевизор выключен";
const string TV_ON_INFO = "Телевизор включен";
const string TV_SELECTED_CHANNEL = "Выбран ";

class CTVSet
{
private:
	bool turnedOn = false;
	int channel = 1;
public:
	void turnOn();
	void turnOff();
	void selectChannel(int);
	void info();
};