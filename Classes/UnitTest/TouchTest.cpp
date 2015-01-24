#ifdef ENABLE_TDD
//
//  TouchTest.m
//	TDD Framework 
//
//
#include "TouchTest.h"
#include "TDDHelper.h"

void TouchTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
	
	this->hideMenu();
	
	
	addTouchSprite();
	
	
	//
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	
	listener->onTouchBegan = CC_CALLBACK_2(TouchTest::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(TouchTest::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(TouchTest::onTouchEnded, this);
	
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}


void TouchTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

void TouchTest::addTouchSprite()
{
	mSprite = Sprite::create("icon-o.png");
	mSprite->setPosition(Point(200, 200));
	this->addChild(mSprite);
}

#pragma mark -
#pragma mark List of Sub Tests

void TouchTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(TouchTest::subTest);
}

#pragma mark -
#pragma mark Sub Test Definition
void TouchTest::subTest(Ref *sender)
{
	log("this is a sample subTest");
}

#pragma mark -
#pragma mark Touches
bool TouchTest::onTouchBegan(Touch *touch, Event *event)
{
	CCLOG("Paddle::onTouchBegan id = %d, x = %f, y = %f", touch->getID(),
			touch->getLocation().x, touch->getLocation().y);
	
	Point pos = touch->getLocation();
	pos.y += 50;
	
	mSprite->setPosition(pos);
	
	return true;
}


void TouchTest::onTouchMoved(Touch *touch, Event *event)
{
	Point pos = touch->getLocation();
	pos.y += 50;
	
	mSprite->setPosition(pos);
}


void TouchTest::onTouchEnded(Touch *touch, Event *event)
{
	Point pos = touch->getLocation();
	mSprite->setPosition(pos);
}


#endif
