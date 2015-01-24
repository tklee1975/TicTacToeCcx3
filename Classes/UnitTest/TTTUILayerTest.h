#ifdef ENABLE_TDD
//
//  TTTUILayerTest.h
//
//
#ifndef __TDD_TTTUILayerTest__
#define __TDD_TTTUILayerTest__

// Include Header

#include "TDDTest.h"

// Class Declaration 
class TTTUILayerTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void subTest(Ref *sender);
}; 

#endif

#endif
