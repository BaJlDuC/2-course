#pragma once
#include "CTVSet.h"
#include <string>

using namespace std;

const string CMD_TURN_ON = "TurnOn";
const string CMD_TURN_OFF = "TurnOff";
const string CMD_SELECT_CHANNEL = "SelectChannel";
const string CMD_INFO = "Info";
const string CMD_EXIT = "Exit";
const string UNCORRECT_CHANNEL = "����� ������ ������ ���� �� 1 �� 99\n����� ������� �������";
const string CHANNEL_NOT_ENTER = "����� ������ �� ������ ��� ������ �������\n����� ������� �������";
const string UNCORRECT_CMD = "�������� ����";
const string PROGRAM_EXIT = "�� ����� �� ���������";
const string WELCOME = "�� � ��������� ���������� ����������� �����������\n������ ��������� ������:\n  TurnOn\n  TurnOff\n  SelectChannel <number of channel>\n  Info\n  Exit";

class CmdHandler
{
private:
	string commandPrivate = "";
	int commandNumberPrivate = 0;
	string channelPrivate = "";
	int channelNumberPrivate = 0;
public:
	bool checkChannelNumber(string);
	void setNumberOfCommand(string, int&);
	void commandProcessing(CTVSet);
};