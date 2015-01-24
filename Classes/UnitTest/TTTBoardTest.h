#ifdef ENABLE_TDD
//
//  TTTBoardTest.h
//
//
#ifndef __TDD_TTTBoardTest__
#define __TDD_TTTBoardTest__

// Include Header

#include "TDDTest.h"
class TTTBoard;

// Class Declaration 
class TTTBoardTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testAddBoard(Ref *sender);
	void testBoardListener(Ref *sender);
	void setupBoard();
	
private:
	TTTBoard *mBoard;
}; 

#endif

#endif
