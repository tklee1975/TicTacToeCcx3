#ifdef ENABLE_TDD
//
//  CocosStudioTest.h
//
//
#ifndef __TDD_CocosStudioTest__
#define __TDD_CocosStudioTest__

// Include Header

#include "TDDTest.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"

USING_NS_CC_EXT;
using namespace cocos2d::ui;

// Class Declaration 
class CocosStudioTest : public TDDTest
{
protected:
	virtual void setUp();
	virtual void tearDown();
	virtual void setSubTest(Vector<MenuItem *> &menuArray);
	
private:
	void testSampleCanvas(Ref *sender);
}; 

#endif

#endif
