#ifdef ENABLE_TDD
//
//  TTTChessTest.m
//	TDD Framework 
//
//
#include "TTTChessTest.h"
#include "TDDHelper.h"
#include "TTTChess.h"

void TTTChessTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void TTTChessTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TTTChessTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TTTChessTest::testSetType);
}

#pragma mark -
#pragma mark Sub Test Definition
void TTTChessTest::testSetType(Ref *sender)
{
	log("testSetType");
	float x = 100;
	float y = 100;
	float gridSize = 80;
	Point pos = Point(x, y);
	
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			TTTChess::Type type = (j+i % 2) == 0 ? TTTChess::Type::CROSS : TTTChess::Type::CIRCLE;
			
			TTTChess *chess = TTTChess::create();
			chess->setPosition(pos);
			chess->setType(type);
			
			addChildToBackground(chess);
			
			pos.x += gridSize;
		}
		
		pos.x = x;
		pos.y += gridSize;
	}
}


#endif
