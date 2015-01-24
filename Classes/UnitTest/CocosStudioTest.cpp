#ifdef ENABLE_TDD
//
//  CocosStudioTest.m
//	TDD Framework 
//
//
#include "CocosStudioTest.h"
#include "TDDHelper.h"
#include "extensions/cocos-ext.h"

#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"

using namespace cocos2d;
using namespace cocostudio::timeline;


void CocosStudioTest::setUp()
{
	log("TDD Setup is called");
	log("Please write somethings");
}


void CocosStudioTest::tearDown()
{
	log("TDD tearDown is called");
	log("Please do clean up here");
}

#pragma mark -
#pragma mark List of Sub Tests

void CocosStudioTest::setSubTest(Vector<MenuItem *> &menuArray)
{
	SUBTEST(CocosStudioTest::testSampleCanvas);
}

#pragma mark -
#pragma mark Sub Test Definition
void CocosStudioTest::testSampleCanvas(Ref *sender)
{
	log("testSampleCanvas");
	
	FileUtils::getInstance()->addSearchPath("gui");
	
	Node *rootNode = CSLoader::createNode("TestScene.csb");
	addChild(rootNode);
	
	Button *button = dynamic_cast<Button*>(rootNode->getChildByName("testButton"));
	
	if(button != NULL) {
		button->setTitleText("Testing");
		button->addClickEventListener([](Ref *) {
				log("Clicked");
			}
		);
	} else {
		log("button is NULL");
	}
}


#endif
