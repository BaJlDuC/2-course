#include <iostream>
#include <string>
#include "ÑmdHandler.h"
#include "CTVSet.h"

typedef pair<int, string> commands;
commands TurnOn(1, "TurnOn");
commands TurnOff(2, "TurnOff");
commands SelectChannel(3, "SelectChannel");
commands Info(4, "Info");
commands Exit(5, "Exit");
enum cmdNumbers{cmdTurnOn = 1, cmdTurnOff, cmdSelectChannel, cmdInfo, cmdExit};

bool CmdHandler::checkChannelNumber(string channelNumber)
{
	channelPrivate = channelNumber;
	for (int i = 1; i != channelNumber.size(); i++)
	{
		if (!isdigit(channelNumber[i]))
		{
			return false;
		}
	}
	return true;
}

void CmdHandler::setNumberOfCommand(string command, int &commandNumber) 
{
	if (command == TurnOn.second) 
	{
		commandNumber = TurnOn.first;
	}
	if (command == TurnOff.second)
	{
		commandNumber = TurnOff.first;
	}
	if (command == SelectChannel.second)
	{
		commandNumber = SelectChannel.first;
	}
	if (command == Info.second)
	{
		commandNumber = Info.first;
	}
	if (command == Exit.second)
	{
		commandNumber = Exit.first;
	}
	if ((command != TurnOn.second) &&
		(command != TurnOff.second) &&
		(command != SelectChannel.second) &&
		(command != Info.second) &&
		(command != Exit.second))
	{
		commandNumber = 0;
	}
	commandNumberPrivate = commandNumber;
}

void CmdHandler::commandProcessing(CTVSet TV)
{
	string command;
	string channel;
	int commandNumber = 0;
	int channelNumber = 0;
	while (command != CMD_EXIT)
	{
		cin >> command;
		commandPrivate = command;
		setNumberOfCommand(commandPrivate, commandNumberPrivate);
		switch (commandNumberPrivate) 
		{
		case(cmdTurnOn):
			TV.turnOn();
			break;
		case(cmdTurnOff):
			TV.turnOff();
			break;
		case(cmdSelectChannel):                 
			cin.ignore(0, '\n');
			getline(cin, channel);
			channelPrivate = channel;
			if ((!channelPrivate.empty()) && (checkChannelNumber(channelPrivate)))
			{
				channelNumber = stoi(channel);
				channelNumberPrivate = channelNumber;
				if ((channelNumberPrivate > 0) && (channelNumberPrivate < 100))
				{
					TV.selectChannel(channelNumberPrivate); 
				}
				else
				{
					cout << UNCORRECT_CHANNEL << endl;
				}
			}
			else
			{
				cout << CHANNEL_NOT_ENTER << endl;
			}
			break;
		case(cmdInfo):
			TV.info();
			break;
		case(cmdExit):
			cout << PROGRAM_EXIT << endl;
			break;
		default:
			cout << UNCORRECT_CMD << endl;
			break;
		}
	}
}