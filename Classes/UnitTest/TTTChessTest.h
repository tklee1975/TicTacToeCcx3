#ifdef ENABLE_TDD
//
//  TTTChessTest.h
//
//
#ifndef __TDD_TTTChessTest__
#define __TDD_TTTChessTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TTTChessTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testSetType(Ref *sender);
}; 

#endif

#endif
