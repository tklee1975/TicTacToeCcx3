#ifdef ENABLE_TDD
//
//  SoundTest.m
//	TDD Framework 
//
//
#include "SoundTest.h"
#include "TDDHelper.h"

#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;

void SoundTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void SoundTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void SoundTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(SoundTest::subTest);
	SUBTEST(SoundTest::testEffect);
}

#pragma mark -
#pragma mark Sub Test Definition
void SoundTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/draw.mp3");
//	SimpleAudioEngine::getInstance()->preloadEffect("");
	SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/draw.mp3", false);
}

void SoundTest::testEffect(Ref *sender)
{
	log("this is a sample subTest");
	SimpleAudioEngine::getInstance()->preloadEffect("sound/move.mp3");
	SimpleAudioEngine::getInstance()->playEffect("sound/move.mp3");
}


#endif
