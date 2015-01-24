#ifdef ENABLE_TDD
//
//  TTTBoardLogicTest.m
//	TDD Framework 
//
//
#include "TTTBoardLogicTest.h"
#include "TDDHelper.h"
#include "TTTBoardLogic.h"

void TTTBoardLogicTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void TTTBoardLogicTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TTTBoardLogicTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TTTBoardLogicTest::subTest);
	SUBTEST(TTTBoardLogicTest::testCheckV);
	SUBTEST(TTTBoardLogicTest::testCheckH);
	SUBTEST(TTTBoardLogicTest::testCheckDiagonal);
	SUBTEST(TTTBoardLogicTest::testDrawGame);
}

#pragma mark -
#pragma mark Sub Test Definition
void TTTBoardLogicTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	
	TTTBoardLogic *logic = new TTTBoardLogic();
	
	logic->placeChess(1, 0, 1);
	logic->placeChess(1, 1, 1);
	logic->placeChess(2, 2, 2);
	
	std::string info;
	
	logic->info(info);

	log("DEBUG:\n%s\n", info.c_str());
}

void TTTBoardLogicTest::testCheckV(Ref *sender)
{
	log("this is a sample subTest");
	
	TTTBoardLogic *logic = new TTTBoardLogic();
	
	logic->placeChess(1, 0, 1);
	logic->placeChess(1, 1, 1);
	logic->placeChess(1, 2, 1);
	logic->placeChess(2, 2, 2);
	
	std::string info;
	
	logic->info(info);
	
	log("DEBUG:\n%s\n", info.c_str());
	
	TTTBoardLogic::Result result = logic->check();
	
	log("result: %d", result);
}


void TTTBoardLogicTest::testCheckH(Ref *sender)
{
	log("this is a sample subTest");
	
	TTTBoardLogic *logic = new TTTBoardLogic();
	
	logic->placeChess(1, 0, 1);
	logic->placeChess(1, 2, 1);
	logic->placeChess(1, 1, 1);
	logic->placeChess(2, 2, 2);
	
	std::string info;
	
	logic->info(info);
	
	log("DEBUG:\n%s\n", info.c_str());
	
	TTTBoardLogic::Result result = logic->check();
	
	log("result: %d", result);
}

void TTTBoardLogicTest::testCheckDiagonal(Ref *sender)
{
	log("testCheckDiagonal");
	
	TTTBoardLogic *logic = new TTTBoardLogic();
	
	logic->placeChess(1, 0, 0);
	logic->placeChess(1, 1, 1);
	logic->placeChess(1, 2, 2);
	logic->placeChess(2, 2, 1);
	
	std::string info;
	
	logic->info(info);
	
	log("DEBUG:\n%s\n", info.c_str());
	
	TTTBoardLogic::Result result = logic->check();
	
	log("result: %d", result);
}

void TTTBoardLogicTest::testDrawGame(Ref *sender)
{
	log("testCheckDiagonal");
	
	TTTBoardLogic *logic = new TTTBoardLogic();

	// Case of draw game
//	1 2 2
//	2 1 1
//	1 1 2
	
	// arg order: playerID, x, y
	logic->placeChess(1, 0, 0);
	logic->placeChess(2, 1, 0);
	logic->placeChess(2, 2, 0);
	
	logic->placeChess(2, 0, 1);
	logic->placeChess(1, 1, 1);
	logic->placeChess(1, 2, 1);
	
	logic->placeChess(1, 0, 2);
	logic->placeChess(1, 1, 2);
	logic->placeChess(2, 2, 2);
	
	
	std::string info;
	
	logic->info(info);
	
	log("DEBUG:\n%s\n", info.c_str());
	
	TTTBoardLogic::Result result = logic->check();
	
	log("result: %d", result);
}



#endif
