#define CATCH_CONFIG_MAIN
#include "..\..\catch2\catch.hpp"
#include "..\ex1-var4\CTimeh.h"
#include "pch.h"
#include <iostream>
#include <stdexcept>

using namespace std;

TEST_CASE("+ tests")
{
	CTime time1(10, 20, 40);
	CTime time2(6, 10, 15);
	CTime time3(11, 55, 55);
	CHECK((time1 + time2).GetHours() == 16);
	CHECK((time1 + time2).GetMinutes() == 30);
	CHECK((time1 + time2).GetSeconds() == 55);

	CHECK((time1 + time3).GetSeconds() == 35);
	CHECK((time1 + time3).GetMinutes() == 16);
	CHECK((time1 + time3).GetHours() == 22);
}

TEST_CASE("- tests")
{
	CTime time1(16, 30, 45);
	CTime time2(10, 20, 15);
	CTime time3(12, 35, 30);

	CHECK((time1 - time2).GetHours() == 6);
	CHECK((time1 - time2).GetMinutes() == 10);
	CHECK((time1 - time2).GetSeconds() == 30);

	CHECK((time1 - time3).GetHours() == 3);
	CHECK((time1 - time3).GetMinutes() == 55);
	CHECK((time1 - time3).GetSeconds() == 15);

	CHECK((time2 - time3).GetHours() == 57);
	CHECK((time2 - time3).GetMinutes() == 44);
	CHECK((time2 - time3).GetSeconds() == 45);
}

TEST_CASE("++ tests")
{
	CTime time1(10, 12, 40);
	CTime time2(10, 40, 59);
	CTime time3(12, 59, 59);
	CTime time4(23, 59, 59);

	CHECK((time1++).GetSeconds() == 41);

	CHECK((time2++).GetSeconds() == 0);
	CHECK((time2++).GetMinutes() == 41);

	CHECK((time3++).GetSeconds() == 0);
	CHECK((time3++).GetMinutes() == 0);
	CHECK((time3++).GetHours() == 13);

	CHECK((time4++).GetSeconds() == 0);
	CHECK((time4++).GetMinutes() == 0);
	CHECK((time4++).GetHours() == 0);
}

TEST_CASE("-- tests")
{
	CTime time1(12, 30, 45);
	CTime time2(12, 40, 0);
	CTime time3(12, 0, 0);
	CTime time4(0, 0, 0);

	CHECK((time1--).GetSeconds() == 44);

	CHECK((time2--).GetSeconds() == 59);
	CHECK((time2--).GetMinutes() == 39);
	CHECK((time2--).GetHours() == 12);

	CHECK((time3--).GetSeconds() == 59);
	CHECK((time3--).GetMinutes() == 59);
	CHECK((time3--).GetHours() == 11);

	CHECK((time4--).GetSeconds() == 59);
	CHECK((time4--).GetMinutes() == 59);
	CHECK((time4--).GetHours() == 23);
}

TEST_CASE("* tests")
{
	CTime time1(2, 4, 10);

	CHECK((time1 * 3).GetSeconds() == 30);
	CHECK((time1 * 3).GetMinutes() == 12);
	CHECK((time1 * 3).GetHours() == 6);

	CHECK((time1 * 7).GetSeconds() == 10);
	CHECK((time1 * 7).GetMinutes() == 29);
	CHECK((time1 * 7).GetHours() == 14);

	CHECK((time1 * 13).GetSeconds() == 10);
	CHECK((time1 * 13).GetMinutes() == 54);
	CHECK((time1 * 13).GetHours() == 2);
	//-----------------------------------
	CHECK((3 * time1).GetSeconds() == 30);
	CHECK((3 * time1).GetMinutes() == 12);
	CHECK((3 * time1).GetHours() == 6);

	CHECK((7 * time1).GetSeconds() == 10);
	CHECK((7 * time1).GetMinutes() == 29);
	CHECK((7 * time1).GetHours() == 14);

	CHECK((13 * time1).GetSeconds() == 10);
	CHECK((13 * time1).GetMinutes() == 54);
	CHECK((13 * time1).GetHours() == 2);
}

TEST_CASE("/ tests")
{
	CTime time1(12, 30, 45);
	CTime time2(4, 10, 15);
	CTime time3(16, 12, 30);

	CTime time4(0, 0, 0);

	CTime time5(0, 4, 0);
	CTime time6(0, 15, 5);
	CTime time7(12, 30, 0);
	CTime time8(1, 10, 20);
	CTime time9(0, 10, 0);

	CHECK((time8 / time5).GetHours() == 0); //новые
	CHECK((time8 / time5).GetMinutes() == 17);
	CHECK((time8 / time5).GetSeconds() == 20);

	CHECK((time3 / time6).GetHours() == 1);
	CHECK((time3 / time6).GetMinutes() == 4);
	CHECK((time3 / time6).GetSeconds() == 6);

	CHECK((time8 / time9).GetHours() == 0);
	CHECK((time8 / time9).GetMinutes() == 7);
	CHECK((time8 / time9).GetSeconds() == 20); //


	CHECK((time1 / time2).GetHours() == 3);
	CHECK((time1 / time2).GetMinutes() == 3);
	CHECK((time1 / time2).GetSeconds() == 3);

	CHECK((time1 / time3).GetHours() == 0);
	CHECK((time1 / time3).GetMinutes() == 2);
	CHECK((time1 / time3).GetSeconds() == 1);

	CHECK((time1 / 4).GetHours() == 3);
	CHECK((time1 / 10).GetMinutes() == 3);
	CHECK((time1 / 15).GetSeconds() == 3);

	CHECK((time1 / 16).GetHours() == 0);
	CHECK((time1 / 12).GetMinutes() == 2);
	CHECK((time1 / 30).GetSeconds() == 1);

	try
	{
		(time1 / 0).GetHours();
		(time1 / 0).GetMinutes();
		(time1 / 0).GetSeconds();
	}
	catch (runtime_error err)
	{
		cout << "Runtime error: " << err.what() << endl;
		CHECK(strcmp(err.what(), "Division by zero") == 0);
	}
	try
	{
		(time1 / time4).GetHours();
		(time1 / time4).GetMinutes();
		(time1 / time4).GetSeconds();
	}
	catch (runtime_error err)
	{
		cout << "Runtime error: " << err.what() << endl;
		CHECK(strcmp(err.what(), "Division by zero") == 0);
	}
}

TEST_CASE("bool operator tests")
{
	CTime time1(12, 30, 30);
	CTime time2(12, 30, 30);
	CTime time3(16, 50, 55);

	CHECK((time1 == time2));
	CHECK((time1 != time3));
	CHECK((time3 > time1));
	CHECK((time1 < time3));
	CHECK((time3 >= time1));
	CHECK((time1 >= time2));
	CHECK((time1 <= time3));
	CHECK((time1 <= time2));
}

TEST_CASE("isValid tests")
{
	CTime validTime(23, 59, 59);
	CTime invalidTime(24, 60, 60);

	CHECK(validTime.isValid() == true);
	CHECK(invalidTime.isValid() == false);
}