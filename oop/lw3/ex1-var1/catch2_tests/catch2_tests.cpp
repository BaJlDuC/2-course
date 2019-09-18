//#include <iostream>
//#include "pch.h"
#include "..\ex1-var1\CTVSet.h"
#include "..\ex1-var1\СmdHandler.h"
#define CATCH_CONFIG_MAIN
#include "..\..\catch2\catch.hpp"

TEST_CASE("CMDHandler checkChannelNumber")
{
	CmdHandler cmdHandler;
	int cmdNumber = 0;
	CHECK(cmdHandler.checkChannelNumber("42") == true);
	CHECK(cmdHandler.checkChannelNumber("4four") == false);
	CHECK(cmdHandler.checkChannelNumber("Three") == false);
}

TEST_CASE("CMDHandler setNumberOfCommand")
{
	CmdHandler cmdHandler;
	int cmdNumber = 0;
	cmdHandler.setNumberOfCommand("TurnOn", cmdNumber);
	CHECK(cmdNumber == 1);
	cmdHandler.setNumberOfCommand("TurnOff", cmdNumber);
	CHECK(cmdNumber == 2);
	cmdHandler.setNumberOfCommand("SelectChannel", cmdNumber);
	CHECK(cmdNumber == 3);
	cmdHandler.setNumberOfCommand("Info", cmdNumber);
	CHECK(cmdNumber == 4);
	cmdHandler.setNumberOfCommand("Exit", cmdNumber);
	CHECK(cmdNumber == 5);
	cmdHandler.setNumberOfCommand(" ", cmdNumber);
	CHECK(cmdNumber == 0);
}