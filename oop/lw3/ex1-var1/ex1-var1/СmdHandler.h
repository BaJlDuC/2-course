#pragma once
#include "CTVSet.h"
#include <string>

using namespace std;

const string CMD_TURN_ON = "TurnOn";
const string CMD_TURN_OFF = "TurnOff";
const string CMD_SELECT_CHANNEL = "SelectChannel";
const string CMD_INFO = "Info";
const string CMD_EXIT = "Exit";
const string UNCORRECT_CHANNEL = "Номер канала должен быть от 1 до 99\nКанал остался прежним";
const string CHANNEL_NOT_ENTER = "Номер канала не введен или введен неверно\nКанал остался прежним";
const string UNCORRECT_CMD = "Неверный ввод";
const string PROGRAM_EXIT = "Вы вышли из программы";
const string WELCOME = "Вы в программе управления виртуальным телевизором\nСписок доступных команд:\n  TurnOn\n  TurnOff\n  SelectChannel <number of channel>\n  Info\n  Exit";

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