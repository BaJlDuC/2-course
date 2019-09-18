#include <iostream>
#include <string>
#include "CTVSet.h"
#include "ÑmdHandler.h"

using namespace std;

void CTVSet::turnOn()
	{
		if (turnedOn == false)
		{
			cout << TV_TURNED_ON << endl;
			turnedOn = true;
		}
		else
		{
			cout << TV_TURNED_ON_NOW << endl;
		}
	}

void CTVSet::turnOff()
	{
		if (turnedOn == true)
		{
			cout << TV_TURNED_OFF << endl;
			turnedOn = false;
		}
		else
		{
			cout << TV_TURNED_OFF_NOW << endl;
		}
	}

void CTVSet::selectChannel(int channelNumber)
	{
		if (turnedOn == true)
		{
			cout << TV_YOU_SWITCH << channelNumber << TV_NUMBER_OF_CHANNEL << endl;
			channel = channelNumber;
		}
		else
		{
			cout << TV_OFF_IMPOSSIBLE_SWITCHING << endl;
		}
	}

void CTVSet::info()
	{
		if (turnedOn == false)
		{
			cout << TV_OFF_INFO << endl;
		}
		else
		{
			cout << TV_ON_INFO << endl;
			cout << TV_SELECTED_CHANNEL << channel << TV_NUMBER_OF_CHANNEL << endl;
		}
	}