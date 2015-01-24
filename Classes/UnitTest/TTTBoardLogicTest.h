#ifdef ENABLE_TDD
//
//  TTTBoardLogicTest.h
//
//
#ifndef __TDD_TTTBoardLogicTest__
#define __TDD_TTTBoardLogicTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TTTBoardLogicTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
	void testCheckV(Ref *sender);
	void testCheckH(Ref *sender);
	void testCheckDiagonal(Ref *sender);
	void testDrawGame(Ref *sender);
}; 

#endif

#endif
