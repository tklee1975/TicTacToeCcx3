#ifdef ENABLE_TDD
//
//  TTTBoardTest.m
//	TDD Framework 
//
//
#include "TTTBoardTest.h"
#include "TDDHelper.h"
#include "TTTBoard.h"

void TTTBoardTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	//setupBoard();
}


void TTTBoardTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TTTBoardTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TTTBoardTest::testAddBoard);
	SUBTEST(TTTBoardTest::testBoardListener);
}


#pragma mark -
#pragma mark General Utility 
void TTTBoardTest::setupBoard()
{
	TTTBoard *board = TTTBoard::createWithSize(300);
	
	float y = 200;
	float x = (320 - (board->getContentSize()).width) / 2;
	board->setPosition(Point(x, y));
	addChild(board, 0);
	mBoard = board;
}

#pragma mark -
#pragma mark Sub Test Definition
void TTTBoardTest::testAddBoard(Ref *sender)
{
	log("testAddBoard");
	
	
	TTTBoard *board = TTTBoard::createWithSize(300);
	
	float x = (320 - (board->getContentSize()).width) / 2;
	board->setPosition(Point(x, 300));
	
	addChildToBackground(board);
}

void TTTBoardTest::testBoardListener(Ref *sender)
{
	log("testAddBoard");
	
	
	TTTBoard *board = TTTBoard::createWithSize(300);
	
	float x = (320 - (board->getContentSize()).width) / 2;
	board->setPosition(Point(x, 200));
	
	addChildToBackground(board);
	
	board->reset();
	board->setEnable(true);
	board->setBoardListener([](Ref *, TTTBoard::State state) {
		log("debug: state=%d", state);
	});
	
	
}


#endif
