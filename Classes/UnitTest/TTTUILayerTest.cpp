#ifdef ENABLE_TDD
//
//  TTTUILayerTest.m
//	TDD Framework 
//
//
#include "TTTUILayerTest.h"
#include "TDDHelper.h"
#include "TTTUILayer.h"

void TTTUILayerTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	TTTUILayer *layer = TTTUILayer::create();
	
	addChild(layer);
	
	hideMenu();

}


void TTTUILayerTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void TTTUILayerTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TTTUILayerTest::subTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void TTTUILayerTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	
	}


#endif
