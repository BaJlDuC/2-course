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

	CTime time6_2_0(6, 2, 0);
	CTime time0_15_5(0, 15, 5);
	CTime time5_0_10(5, 0, 10);
	CTime time3_0_0(3, 0, 0);
	CTime time0_4_0(0, 4, 0);
	CTime time0_0_12(0, 0, 12);

	CTime time19_48_55(19, 48, 55);

	CHECK((time6_2_0 + time0_15_5).GetHours() == 6);
	CHECK((time6_2_0 + time0_15_5).GetMinutes() == 17);
	CHECK((time6_2_0 + time0_15_5).GetSeconds() == 5);

	CHECK((time6_2_0 + time5_0_10).GetHours() == 11);
	CHECK((time6_2_0 + time5_0_10).GetMinutes() == 2);
	CHECK((time6_2_0 + time5_0_10).GetSeconds() == 10);

	CHECK((time6_2_0 + time3_0_0).GetHours() == 9);
	CHECK((time6_2_0 + time3_0_0).GetMinutes() == 2);
	CHECK((time6_2_0 + time3_0_0).GetSeconds() == 0);

	CHECK((time6_2_0 + time0_4_0).GetHours() == 6);
	CHECK((time6_2_0 + time0_4_0).GetMinutes() == 6);
	CHECK((time6_2_0 + time0_4_0).GetSeconds() == 0);

	CHECK((time6_2_0 + time0_0_12).GetHours() == 6);
	CHECK((time6_2_0 + time0_0_12).GetMinutes() == 2);
	CHECK((time6_2_0 + time0_0_12).GetSeconds() == 12);
	//====================

	CHECK((time0_15_5 + time5_0_10).GetHours() == 5);
	CHECK((time0_15_5 + time5_0_10).GetMinutes() == 15);
	CHECK((time0_15_5 + time5_0_10).GetSeconds() == 15);

	CHECK((time0_15_5 + time3_0_0).GetHours() == 3);
	CHECK((time0_15_5 + time3_0_0).GetMinutes() == 15);
	CHECK((time0_15_5 + time3_0_0).GetSeconds() == 5);

	CHECK((time0_15_5 + time0_4_0).GetHours() == 0);
	CHECK((time0_15_5 + time0_4_0).GetMinutes() == 19);
	CHECK((time0_15_5 + time0_4_0).GetSeconds() == 5);

	CHECK((time0_15_5 + time0_0_12).GetHours() == 0);
	CHECK((time0_15_5 + time0_0_12).GetMinutes() == 15);
	CHECK((time0_15_5 + time0_0_12).GetSeconds() == 17);
	//======================

	CHECK((time5_0_10 + time3_0_0).GetHours() == 8);
	CHECK((time5_0_10 + time3_0_0).GetMinutes() == 0);
	CHECK((time5_0_10 + time3_0_0).GetSeconds() == 10);

	CHECK((time5_0_10 + time0_4_0).GetHours() == 5);
	CHECK((time5_0_10 + time0_4_0).GetMinutes() == 4);
	CHECK((time5_0_10 + time0_4_0).GetSeconds() == 10);

	CHECK((time5_0_10 + time0_0_12).GetHours() == 5);
	CHECK((time5_0_10 + time0_0_12).GetMinutes() == 0);
	CHECK((time5_0_10 + time0_0_12).GetSeconds() == 22);
	//====================

	CHECK((time3_0_0 + time0_4_0).GetHours() == 3);
	CHECK((time3_0_0 + time0_4_0).GetMinutes() == 4);
	CHECK((time3_0_0 + time0_4_0).GetSeconds() == 0);

	CHECK((time3_0_0 + time0_0_12).GetHours() == 3);
	CHECK((time3_0_0 + time0_0_12).GetMinutes() == 0);
	CHECK((time3_0_0 + time0_0_12).GetSeconds() == 12);

	CHECK((time0_4_0 + time0_0_12).GetHours() == 0);
	CHECK((time0_4_0 + time0_0_12).GetMinutes() == 4);
	CHECK((time0_4_0 + time0_0_12).GetSeconds() == 12);


	CHECK((time19_48_55 + time6_2_0).GetHours() == 1);
	CHECK((time19_48_55 + time6_2_0).GetMinutes() == 50);
	CHECK((time19_48_55 + time6_2_0).GetSeconds() == 55);

	CHECK((time19_48_55 + time0_15_5).GetHours() == 20);
	CHECK((time19_48_55 + time0_15_5).GetMinutes() == 4);
	CHECK((time19_48_55 + time0_15_5).GetSeconds() == 0);

	CHECK((time19_48_55 + time5_0_10).GetHours() == 0);
	CHECK((time19_48_55 + time5_0_10).GetMinutes() == 49);
	CHECK((time19_48_55 + time5_0_10).GetSeconds() == 5);

	CHECK((time19_48_55 + time3_0_0).GetHours() == 22);
	CHECK((time19_48_55 + time3_0_0).GetMinutes() == 48);
	CHECK((time19_48_55 + time3_0_0).GetSeconds() == 55);

	CHECK((time19_48_55 + time0_4_0).GetHours() == 19);
	CHECK((time19_48_55 + time0_4_0).GetMinutes() == 52);
	CHECK((time19_48_55 + time0_4_0).GetSeconds() == 55);

	CHECK((time19_48_55 + time0_0_12).GetHours() == 19);
	CHECK((time19_48_55 + time0_0_12).GetMinutes() == 49);
	CHECK((time19_48_55 + time0_0_12).GetSeconds() == 7);


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

	CTime time6_2_0(6, 2, 0);
	CTime time0_15_5(0, 15, 5);
	CTime time5_0_10(5, 0, 10);
	CTime time3_0_0(3, 0, 0);
	CTime time0_4_0(0, 4, 0);
	CTime time0_0_12(0, 0, 12);

	CTime time4_40_15(4, 40, 15);

	CHECK((time6_2_0 - time0_15_5).GetHours() == 5);
	CHECK((time6_2_0 - time0_15_5).GetMinutes() == 46);
	CHECK((time6_2_0 - time0_15_5).GetSeconds() == 55);

	CHECK((time6_2_0 - time5_0_10).GetHours() == 1);
	CHECK((time6_2_0 - time5_0_10).GetMinutes() == 1);
	CHECK((time6_2_0 - time5_0_10).GetSeconds() == 50);

	CHECK((time6_2_0 - time3_0_0).GetHours() == 3);
	CHECK((time6_2_0 - time3_0_0).GetMinutes() == 2);
	CHECK((time6_2_0 - time3_0_0).GetSeconds() == 0);

	CHECK((time6_2_0 - time0_4_0).GetHours() == 5);
	CHECK((time6_2_0 - time0_4_0).GetMinutes() == 58);
	CHECK((time6_2_0 - time0_4_0).GetSeconds() == 0);

	CHECK((time6_2_0 - time0_0_12).GetHours() == 6);
	CHECK((time6_2_0 - time0_0_12).GetMinutes() == 1);
	CHECK((time6_2_0 - time0_0_12).GetSeconds() == 48);
	//=======================

	CHECK((time0_15_5 - time5_0_10).GetHours() == 19);
	CHECK((time0_15_5 - time5_0_10).GetMinutes() == 14);
	CHECK((time0_15_5 - time5_0_10).GetSeconds() == 55);

	CHECK((time0_15_5 - time3_0_0).GetHours() == 21);
	CHECK((time0_15_5 - time3_0_0).GetMinutes() == 15);
	CHECK((time0_15_5 - time3_0_0).GetSeconds() == 5);

	CHECK((time0_15_5 - time0_4_0).GetHours() == 0);
	CHECK((time0_15_5 - time0_4_0).GetMinutes() == 11);
	CHECK((time0_15_5 - time0_4_0).GetSeconds() == 5);

	CHECK((time0_15_5 - time0_0_12).GetHours() == 0);
	CHECK((time0_15_5 - time0_0_12).GetMinutes() == 14);
	CHECK((time0_15_5 - time0_0_12).GetSeconds() == 53);
    //===================

	CHECK((time5_0_10 - time3_0_0).GetHours() == 2);
	CHECK((time5_0_10 - time3_0_0).GetMinutes() == 0);
	CHECK((time5_0_10 - time3_0_0).GetSeconds() == 10);

	CHECK((time5_0_10 - time0_4_0).GetHours() == 4);
	CHECK((time5_0_10 - time0_4_0).GetMinutes() == 56);
	CHECK((time5_0_10 - time0_4_0).GetSeconds() == 10);

	CHECK((time5_0_10 - time0_0_12).GetHours() == 4);
	CHECK((time5_0_10 - time0_0_12).GetMinutes() == 59);
	CHECK((time5_0_10 - time0_0_12).GetSeconds() == 58);
	//========================

	CHECK((time3_0_0 - time0_4_0).GetHours() == 2);
	CHECK((time3_0_0 - time0_4_0).GetMinutes() == 56);
	CHECK((time3_0_0 - time0_4_0).GetSeconds() == 0);

	CHECK((time3_0_0 - time0_0_12).GetHours() == 2);
	CHECK((time3_0_0 - time0_0_12).GetMinutes() == 59);
	CHECK((time3_0_0 - time0_0_12).GetSeconds() == 48);
	//==========================

	CHECK((time4_40_15 - time0_0_12).GetHours() == 4);
	CHECK((time4_40_15 - time0_0_12).GetMinutes() == 40);
	CHECK((time4_40_15 - time0_0_12).GetSeconds() == 3);

	CHECK((time4_40_15 - time3_0_0).GetHours() == 1);
	CHECK((time4_40_15 - time3_0_0).GetMinutes() == 40);
	CHECK((time4_40_15 - time3_0_0).GetSeconds() == 15);

	CHECK((time4_40_15 - time0_0_12).GetHours() == 4);
	CHECK((time4_40_15 - time0_0_12).GetMinutes() == 40);
	CHECK((time4_40_15 - time0_0_12).GetSeconds() == 3);

	CHECK((time4_40_15 - time5_0_10).GetHours() == 23);
	CHECK((time4_40_15 - time5_0_10).GetMinutes() == 40);
	CHECK((time4_40_15 - time5_0_10).GetSeconds() == 5);

	CHECK((time4_40_15 - time0_15_5).GetHours() == 4);
	CHECK((time4_40_15 - time0_15_5).GetMinutes() == 25);
	CHECK((time4_40_15 - time0_15_5).GetSeconds() == 10);

	CHECK((time4_40_15 - time6_2_0).GetHours() == 22);
	CHECK((time4_40_15 - time6_2_0).GetMinutes() == 38);
	CHECK((time4_40_15 - time6_2_0).GetSeconds() == 15);


	CHECK((time1 - time2).GetHours() == 6);
	CHECK((time1 - time2).GetMinutes() == 10);
	CHECK((time1 - time2).GetSeconds() == 30);

	CHECK((time1 - time3).GetHours() == 3);
	CHECK((time1 - time3).GetMinutes() == 55);
	CHECK((time1 - time3).GetSeconds() == 15);

	CHECK((time2 - time3).GetHours() == 21);
	CHECK((time2 - time3).GetMinutes() == 44);
	CHECK((time2 - time3).GetSeconds() == 45);
}

TEST_CASE("++ tests")
{
	CTime time1(10, 12, 40);
	CTime time2(10, 40, 59);
	CTime time3(12, 59, 59);
	CTime time4(23, 59, 59);
	CTime time0_14_33(0, 14, 33);
	CTime time11_0_21(11, 0, 21);
	CTime time13_32_0(13, 32, 0);
	CTime time1_0_0(1, 0, 0);
	CTime time0_11_0(0, 11, 0);
	CTime time0_0_2(0, 0, 2);

	CHECK((time0_14_33++).GetHours() == 0);
	CHECK((time0_14_33++).GetMinutes() == 14);
	CHECK((time0_14_33++).GetSeconds() == 34);

	CHECK((time11_0_21++).GetHours() == 11);
	CHECK((time11_0_21++).GetMinutes() == 0);
	CHECK((time11_0_21++).GetSeconds() == 22);

	CHECK((time13_32_0++).GetHours() == 13);
	CHECK((time13_32_0++).GetMinutes() == 32);
	CHECK((time13_32_0++).GetSeconds() == 1);

	CHECK((time1_0_0++).GetHours() == 1);
	CHECK((time1_0_0++).GetMinutes() == 0);
	CHECK((time1_0_0++).GetSeconds() == 1);

	CHECK((time0_11_0++).GetHours() == 0);
	CHECK((time0_11_0++).GetMinutes() == 11);
	CHECK((time0_11_0++).GetSeconds() == 1);

	CHECK((time0_0_2++).GetHours() == 0);
	CHECK((time0_0_2++).GetMinutes() == 0);
	CHECK((time0_0_2++).GetSeconds() == 3);

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
	CTime time0_14_33(0, 14, 33);
	CTime time11_0_21(11, 0, 21);
	CTime time0_11_0(0, 11, 0);
	CTime time0_0_2(0, 0, 2);

	CHECK((time0_14_33--).GetHours() == 0);
	CHECK((time0_14_33--).GetMinutes() == 14);
	CHECK((time0_14_33--).GetSeconds() == 32);

	CHECK((time11_0_21--).GetHours() == 11);
	CHECK((time11_0_21--).GetMinutes() == 0);
	CHECK((time11_0_21--).GetSeconds() == 20);

	CHECK((time0_11_0--).GetHours() == 0);
	CHECK((time0_11_0--).GetMinutes() == 10);
	CHECK((time0_11_0--).GetSeconds() == 59);

	CHECK((time0_0_2--).GetHours() == 0);
	CHECK((time0_0_2--).GetMinutes() == 0);
	CHECK((time0_0_2--).GetSeconds() == 1);

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
	CTime time16_40_0(16, 40, 0);
	CTime time16_0_50(16, 0, 50);
	CTime time0_18_35(0, 18, 35);
	CTime time8_0_0(8, 0, 0);
	CTime time0_45_0(0, 45, 0);
	CTime time0_0_20(0, 0, 20);

	try
	{
		(time1 * -5).GetHours();
		(time1 * -5).GetMinutes();
		(time1 * -5).GetSeconds();
	}
	catch (runtime_error err)
	{
		CHECK(strcmp(err.what(), "factor < 0") == 0);
	}

	try
	{
		(-5 * time1).GetHours();
		(-5 * time1).GetMinutes();
		(-5 * time1).GetSeconds();
	}
	catch (runtime_error err)
	{
		CHECK(strcmp(err.what(), "factor < 0") == 0);
	}

	CHECK((time16_40_0 * 2).GetHours() == 9);
	CHECK((time16_40_0 * 2).GetMinutes() == 20);
	CHECK((time16_40_0 * 2).GetSeconds() == 0);

	CHECK((time16_0_50 * 2).GetHours() == 8);
	CHECK((time16_0_50 * 2).GetMinutes() == 1);
	CHECK((time16_0_50 * 2).GetSeconds() == 40);

	CHECK((time0_18_35 * 2).GetHours() == 0);
	CHECK((time0_18_35 * 2).GetMinutes() == 37);
	CHECK((time0_18_35 * 2).GetSeconds() == 10);

	CHECK((time8_0_0 * 2).GetHours() == 16);
	CHECK((time8_0_0 * 2).GetMinutes() == 0);
	CHECK((time8_0_0 * 2).GetSeconds() == 0);

	CHECK((time0_45_0 * 2).GetHours() == 1);
	CHECK((time0_45_0 * 2).GetMinutes() == 30);
	CHECK((time0_45_0 * 2).GetSeconds() == 0);

	CHECK((time0_0_20 * 2).GetHours() == 0);
	CHECK((time0_0_20 * 2).GetMinutes() == 0);
	CHECK((time0_0_20 * 2).GetSeconds() == 40);


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
	CTime time12_30_45(12, 30, 45);
	CTime time4_10_15(4, 10, 15);
	CTime time16_12_30(16, 12, 30);
	CTime time8_2_6(8, 2, 6);

	CTime time0_0_0(0, 0, 0);

	CTime time6_2_0(6, 2, 0);
	CTime time0_15_5(0, 15, 5);
	CTime time5_0_10(5, 0, 10);
	CTime time3_0_0(3, 0, 0);
	CTime time0_4_0(0, 4, 0);
	CTime time0_0_12(0, 0, 12);
	CTime time12_30_0(12, 30, 0);
	CTime time1_10_20(1, 10, 20);
	CTime time0_10_0(0, 10, 0);

	CHECK((time3_0_0 / time0_4_0) == 45); //-----------------------------------------------------
	CHECK((time0_10_0 / time0_4_0) == 2);
	CHECK((time0_0_12 / time0_4_0) == 0);
	CHECK((time12_30_0 / time0_4_0) == 187);
	CHECK((time0_15_5 / time0_4_0) == 3);
	CHECK((time5_0_10 / time0_4_0) == 75);
	CHECK((time8_2_6 / time0_4_0) == 120);

	CHECK((time3_0_0 / time3_0_0) == 1);
	CHECK((time0_10_0 / time3_0_0) == 0);
	CHECK((time0_0_12 / time3_0_0) == 0);
	CHECK((time12_30_0 / time3_0_0) == 4); // деление на времена, содержащих 2 нулевые значения 
	CHECK((time0_15_5 / time3_0_0) == 0);
	CHECK((time5_0_10 / time3_0_0) == 1);
	CHECK((time8_2_6 / time3_0_0) == 2);

	CHECK((time3_0_0 / time0_0_12) == 900);
	CHECK((time0_10_0 / time0_0_12) == 50);
	CHECK((time0_0_12 / time0_0_12) == 1);
	CHECK((time12_30_0 / time0_0_12) == 3750);
	CHECK((time0_15_5 / time0_0_12) == 75);
	CHECK((time5_0_10 / time0_0_12) == 1500);
	CHECK((time8_2_6 / time0_0_12) == 2410); //------------------------------------------------------

	CHECK((time3_0_0 / time6_2_0) == 0); //-----------------------------------------------------
	CHECK((time0_10_0 / time6_2_0) == 0);
	CHECK((time0_0_12 / time6_2_0) == 0);
	CHECK((time12_30_0 / time6_2_0) == 2);
	CHECK((time0_15_5 / time6_2_0) == 0);
	CHECK((time5_0_10 / time6_2_0) == 0);
	CHECK((time8_2_6 / time6_2_0) == 1);

	CHECK((time3_0_0 / time5_0_10) == 0);
	CHECK((time0_10_0 / time5_0_10) == 0);
	CHECK((time0_0_12 / time5_0_10) == 0);
	CHECK((time12_30_0 / time5_0_10) == 2); // деление на времена, содержащих 1 нулевое значение 
	CHECK((time0_15_5 / time5_0_10) == 0);
	CHECK((time5_0_10 / time5_0_10) == 1);
	CHECK((time8_2_6 / time5_0_10) == 1);

	CHECK((time3_0_0 / time0_15_5) == 11);
	CHECK((time0_10_0 / time0_15_5) == 0);
	CHECK((time0_0_12 / time0_15_5) == 0);
	CHECK((time12_30_0 / time0_15_5) == 49);
	CHECK((time0_15_5 / time0_15_5) == 1);
	CHECK((time5_0_10 / time0_15_5) == 19);
	CHECK((time8_2_6 / time0_15_5) == 31); //------------------------------------------------------


	CHECK((time16_12_30 / time12_30_45) == 1);
	CHECK((time16_12_30 / time8_2_6) == 2);
	CHECK((time12_30_45 / time4_10_15) == 3);
	CHECK((time12_30_45 / time16_12_30) == 0);

	//---------------------------------------деление на число
	CHECK((time12_30_45 / 75).GetHours() == 0);
	CHECK((time12_30_45 / 75).GetMinutes() == 10);
	CHECK((time12_30_45 / 75).GetSeconds() == 0);

	CHECK((time12_30_45 / 30).GetHours() == 0);
	CHECK((time12_30_45 / 30).GetMinutes() == 25);
	CHECK((time12_30_45 / 30).GetSeconds() == 1);

	CHECK((time12_30_45 / 3).GetHours() == 4);
	CHECK((time12_30_45 / 3).GetMinutes() == 10);
	CHECK((time12_30_45 / 3).GetSeconds() == 15);

	//------------------------------------------ 1 нулевой параметр
	CHECK((time6_2_0 / 75).GetHours() == 0);
	CHECK((time6_2_0 / 75).GetMinutes() == 4);
	CHECK((time6_2_0 / 75).GetSeconds() == 49);
	CHECK((time6_2_0 / 30).GetHours() == 0); 
	CHECK((time6_2_0 / 30).GetMinutes() == 12);
	CHECK((time6_2_0 / 30).GetSeconds() == 4);
	CHECK((time6_2_0 / 3).GetHours() == 2);
	CHECK((time6_2_0 / 3).GetMinutes() == 0);
	CHECK((time6_2_0 / 3).GetSeconds() == 40);

	CHECK((time5_0_10 / 75).GetHours() == 0);
	CHECK((time5_0_10 / 75).GetMinutes() == 4);
	CHECK((time5_0_10 / 75).GetSeconds() == 0);
	CHECK((time5_0_10 / 30).GetHours() == 0);
	CHECK((time5_0_10 / 30).GetMinutes() == 10);
	CHECK((time5_0_10 / 30).GetSeconds() == 0);
	CHECK((time5_0_10 / 3).GetHours() == 1);
	CHECK((time5_0_10 / 3).GetMinutes() == 40);
	CHECK((time5_0_10 / 3).GetSeconds() == 3);

	CHECK((time0_15_5 / 75).GetHours() == 0);
	CHECK((time0_15_5 / 75).GetMinutes() == 0);
	CHECK((time0_15_5 / 75).GetSeconds() == 12);
	CHECK((time0_15_5 / 30).GetHours() == 0);
	CHECK((time0_15_5 / 30).GetMinutes() == 0);
	CHECK((time0_15_5 / 30).GetSeconds() == 30);
	CHECK((time0_15_5 / 3).GetHours() == 0);
	CHECK((time0_15_5 / 3).GetMinutes() == 5);
	CHECK((time0_15_5 / 3).GetSeconds() == 1);

	//---------------------------------------------2 нулевых параметра
	CHECK((time3_0_0 / 75).GetHours() == 0);
	CHECK((time3_0_0 / 75).GetMinutes() == 2);
	CHECK((time3_0_0 / 75).GetSeconds() == 24);
	CHECK((time3_0_0 / 30).GetHours() == 0);
	CHECK((time3_0_0 / 30).GetMinutes() == 6);
	CHECK((time3_0_0 / 30).GetSeconds() == 0);
	CHECK((time3_0_0 / 3).GetHours() == 1);
	CHECK((time3_0_0 / 3).GetMinutes() == 0);
	CHECK((time3_0_0 / 3).GetSeconds() == 0);

	CHECK((time0_10_0 / 75).GetHours() == 0);
	CHECK((time0_10_0 / 75).GetMinutes() == 0);
	CHECK((time0_10_0 / 75).GetSeconds() == 8);
	CHECK((time0_10_0 / 30).GetHours() == 0);
	CHECK((time0_10_0 / 30).GetMinutes() == 0);
	CHECK((time0_10_0 / 30).GetSeconds() == 20);
	CHECK((time0_10_0 / 3).GetHours() == 0);
	CHECK((time0_10_0 / 3).GetMinutes() == 3);
	CHECK((time0_10_0 / 3).GetSeconds() == 20);

	CHECK((time0_0_12 / 75).GetHours() == 0);
	CHECK((time0_0_12 / 75).GetMinutes() == 0);
	CHECK((time0_0_12 / 75).GetSeconds() == 0);
	CHECK((time0_0_12 / 30).GetHours() == 0);
	CHECK((time0_0_12 / 30).GetMinutes() == 0);
	CHECK((time0_0_12 / 30).GetSeconds() == 0);
	CHECK((time0_0_12 / 3).GetHours() == 0);
	CHECK((time0_0_12 / 3).GetMinutes() == 0);
	CHECK((time0_0_12 / 3).GetSeconds() == 4);

	try
	{
		(time12_30_45 / -4).GetHours();
	
	}
	catch (runtime_error err)
	{
		CHECK(strcmp(err.what(), "divisor < 0") == 0);
	}

	try
	{
		(time12_30_45 / 0).GetHours();
		(time12_30_45 / 0).GetMinutes();
		(time12_30_45 / 0).GetSeconds();
	}
	catch (runtime_error err)
	{
		CHECK(strcmp(err.what(), "Division by zero") == 0);
	}
	try
	{
		(time12_30_45 / time0_0_0);
	}
	catch (runtime_error err)
	{
		CHECK(strcmp(err.what(), "Division by zero") == 0);
	}
}

TEST_CASE("bool operator tests")
{
	CTime time1(12, 30, 30);
	CTime time2(12, 30, 30);
	CTime time3(16, 50, 55);

	CTime time0_15_30(0, 15, 30);
	CTime time1_0_40(1, 0, 40);
	CTime time3_25_0(3, 25, 0);
	CTime time18_0_0(18, 0, 0);
	CTime time0_55_0(0, 55, 0);
	CTime time0_0_10(0, 0, 10);

	CHECK((time0_15_30 > time0_0_10));
	CHECK((time0_15_30 < time1_0_40));
	CHECK((time0_15_30 < time3_25_0));
	CHECK((time0_15_30 < time18_0_0));
	CHECK((time0_15_30 < time0_55_0));

	CHECK((time1_0_40 < time18_0_0));
	CHECK((time1_0_40 < time3_25_0));
	CHECK((time1_0_40 > time0_55_0));
	CHECK((time1_0_40 > time0_0_10));

	CHECK((time3_25_0 > time0_0_10));
	CHECK((time3_25_0 < time18_0_0));
	CHECK((time3_25_0 > time0_55_0));

	CHECK((time18_0_0 > time0_55_0));
	CHECK((time18_0_0 > time0_0_10));

	CHECK((time0_55_0 > time0_0_10));


	CHECK((time0_15_30 >= time0_0_10));
	CHECK((time0_15_30 <= time1_0_40));
	CHECK((time0_15_30 <= time3_25_0));
	CHECK((time0_15_30 <= time18_0_0));
	CHECK((time0_15_30 <= time0_55_0));

	CHECK((time1_0_40 <= time18_0_0));
	CHECK((time1_0_40 <= time3_25_0));
	CHECK((time1_0_40 >= time0_55_0));
	CHECK((time1_0_40 >= time0_0_10));

	CHECK((time3_25_0 >= time0_0_10));
	CHECK((time3_25_0 <= time18_0_0));
	CHECK((time3_25_0 >= time0_55_0));

	CHECK((time18_0_0 >= time0_55_0));
	CHECK((time18_0_0 >= time0_0_10));

	CHECK((time0_55_0 >= time0_0_10));


	CHECK((time0_15_30 != time0_0_10));
	CHECK((time0_15_30 != time1_0_40));
	CHECK((time0_15_30 != time3_25_0));
	CHECK((time0_15_30 != time18_0_0));
	CHECK((time0_15_30 != time0_55_0));

	CHECK((time1_0_40 != time18_0_0));
	CHECK((time1_0_40 != time3_25_0));
	CHECK((time1_0_40 != time0_55_0));
	CHECK((time1_0_40 != time0_0_10));

	CHECK((time3_25_0 != time0_0_10));
	CHECK((time3_25_0 != time18_0_0));
	CHECK((time3_25_0 != time0_55_0));

	CHECK((time18_0_0 != time0_55_0));
	CHECK((time18_0_0 != time0_0_10));

	CHECK((time0_55_0 != time0_0_10));

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
	CTime incorrectTime(-1, -5, 12);
	CTime time24_59_59(24, 59, 59);
	CTime time23_60_59(23, 60, 59);
	CTime time23_59_60(23, 59, 60);

	CTime time23_62_12(23, 62, 12);
	CTime time26_42_30(26, 42, 30);
	CTime time12_30_66(12, 30, 66);

	CTime time0_62_12(0, 62, 12);
	CTime time0_42_30(0, 42, 30);
	CTime time0_30_66(0, 30, 66);

	CTime time23_0_12(23, 0, 12);
	CTime time26_0_30(26, 0, 30);
	CTime time12_0_66(12, 0, 66);

	CTime time23_62_0(23, 62, 0);
	CTime time26_42_0(26, 42, 0);
	CTime time12_30_0(12, 30, 0);

	CTime time0_0_12(0, 0, 12);
	CTime time0_0_30(0, 0, 30);
	CTime time0_0_66(0, 0, 66);

	CTime time0_62_0(0, 62, 0);
	CTime time0_42_0(0, 42, 0);
	CTime time0_30_0(0, 30, 0);

	CTime time23_0_0(23, 0, 0);
	CTime time26_0_0(26, 0, 0);
	CTime time12_0_0(12, 0, 0);

	CHECK((incorrectTime).GetHours() == 4294967295);
	CHECK((incorrectTime).GetMinutes() == 4294967291);
	CHECK((incorrectTime).GetSeconds() == 12);

	CHECK((time24_59_59).isValid() == false);
	CHECK((time23_60_59).isValid() == false);
	CHECK((time23_59_60).isValid() == false);

	CHECK((incorrectTime).isValid() == false);
	CHECK(validTime.isValid() == true);
	CHECK(invalidTime.isValid() == false);

	CHECK((time23_62_12).isValid() == false);
	CHECK((time26_42_30).isValid() == false);
	CHECK((time12_30_66).isValid() == false);

	CHECK((time0_62_12).isValid() == false);
	CHECK((time0_42_30).isValid() == true);
	CHECK((time0_30_66).isValid() == false);

	CHECK((time23_0_12).isValid() == true);
	CHECK((time26_0_30).isValid() == false);
	CHECK((time12_0_66).isValid() == false);

	CHECK((time23_62_0).isValid() == false);
	CHECK((time26_42_0).isValid() == false);
	CHECK((time12_30_0).isValid() == true);

	CHECK((time23_0_0).isValid() == true);
	CHECK((time26_0_0).isValid() == false);
	CHECK((time12_0_0).isValid() == true);

	CHECK((time0_62_0).isValid() == false);
	CHECK((time0_42_0).isValid() == true);
	CHECK((time0_30_0).isValid() == true);

	CHECK((time0_0_12).isValid() == true);
	CHECK((time0_0_30).isValid() == true);
	CHECK((time0_0_66).isValid() == false);
}