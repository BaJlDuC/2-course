#pragma once
#include <string>
#include <iostream>

using namespace std;

const string TV_TURNED_ON = "�� �������� ���������";
const string TV_TURNED_ON_NOW = "��������� ��� �������";
const string TV_TURNED_OFF = "�� ��������� ���������";
const string TV_TURNED_OFF_NOW = "��������� ��� ��������";
const string TV_YOU_SWITCH = "�� ����������� �� ";
const string TV_NUMBER_OF_CHANNEL = "-� �����";
const string TV_OFF_IMPOSSIBLE_SWITCHING = "��������� ��������, ������������ ������ ����������";
const string TV_OFF_INFO = "��������� ��������";
const string TV_ON_INFO = "��������� �������";
const string TV_SELECTED_CHANNEL = "������ ";

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