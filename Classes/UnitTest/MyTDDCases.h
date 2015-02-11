//
//  MyTDDCases.h
//  Cocos2dxTDDLib
//
//	This header should be included by TDDCases.h only
//  Created by Ken Lee on 25/5/14.
//
//


// Add the Header here!
#include "ExampleTest.h"
#include "FontTest.h"
#include "TTTBoardTest.h"
#include "TTTChessTest.h"
#include "TouchTest.h"
#include "CocosStudioTest.h"
#include "TTTUILayerTest.h"
#include "TTTBoardLogicTest.h"
#include "SoundTest.h"

//#include#
// NOTE!!! The above line is used to generate new unit test, must not be removed.

// Define
TDD_CASES
{
	TEST(CocosStudioTest),
	TEST(SoundTest),
	TEST(TTTBoardLogicTest),
	TEST(TTTUILayerTest),
	TEST(TouchTest),
	TEST(ExampleTest),
	TEST(FontTest),
	TEST(TTTChessTest),
	TEST(TTTBoardTest),
//#testcase#
// NOTE!!! The above line is used to generate new unit test, must not be removed.
};


