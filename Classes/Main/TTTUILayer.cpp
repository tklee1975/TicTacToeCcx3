//
//  TTTUILayer.cpp
//  TicTacToe
//
//  Created by Ken Lee on 17/1/15.
//
//

#include "TTTUILayer.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "TTTBoard.h"
#include "TDDHelper.h"

#include "audio/include/SimpleAudioEngine.h"
using namespace CocosDenshion;

#define kSoundWin		"sound/win.mp3"
#define kSoundDraw		"sound/draw.mp3"

using namespace cocos2d;
using namespace cocostudio::timeline;

TTTUILayer *TTTUILayer::create()
{
	TTTUILayer *layer = new TTTUILayer();
	bool isOkay = layer->init();
	
	if(isOkay == false) {
		return NULL;
	}
	
	return layer;
}

// on "init" you need to initialize your instance
bool TTTUILayer::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !Layer::init() )
	{
		return false;
	}
	
	// Setup Detail
	//	- Setup for CocosStudio UI
	//	- Setup the TTTBoard
	//	- Reset to GameStart
	
	// Setup Path so that CocosStudio can find the its files
	FileUtils::getInstance()->addSearchPath("gui");
	
	// Setup UI
	Node *rootNode = CSLoader::createNode("GameLayer.csb");
	addChild(rootNode);
	
	Node *mainPanel = rootNode->getChildByName("mainPanel");
	Node *boardNode = mainPanel->getChildByName("boardPosNode");
	
	// Setup the GUI
	setupUI(mainPanel);
	
	
	// Setup Game Board
	setupBoard(boardNode);
	
	
	// Setup Sound
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(kSoundWin);
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(kSoundDraw);
	
	// Start the game
	changeToStart();
	
	
	// Setting for Testing / Release Version
#ifdef ENABLE_TDD
		Point pos = Point(270, 50);
		TDDHelper::addTestButton(this, pos);
		
		Director::getInstance()->setDisplayStats(true);
#else
		Director::getInstance()->setDisplayStats(false);
#endif
	
	// 
	return true;
}

void TTTUILayer::setupUI(Node *mainPanel)
{
	// Setup the text
	Node *node = mainPanel->getChildByName("statusText");
	mStatusLabel = (Text *) node;
	
	// Setup the playButton
	auto parent = this;
	node = mainPanel->getChildByName("playButton");
	
	mPlayerButton = (Button *)node;
	if(mPlayerButton != NULL) {
		mPlayerButton->addClickEventListener([parent](Ref *) {
			parent->handlePlayClicked();
		});
	}
	
}

void TTTUILayer::setupBoard(Node *boardNode)
{
	Point pos = boardNode->getPosition();
	
	float boardWidth = 300;
	
	TTTBoard *board = TTTBoard::createWithSize(boardWidth);
	
	// Place the board to the right position
	Point boardPos = Point(pos.x - boardWidth/2, pos.y - boardWidth/2);
	
	board->setPosition(boardPos);
	addChild(board);
	
	// Set the Listener
	auto parent = this;
	board->setEnable(false);		// disable the board first
	board->setBoardListener([parent](Ref *, TTTBoard::State state) {
		log("debug: state=%d", state);
		parent->handleBoardState(state);
	});
	
	mBoard = board;
}

void TTTUILayer::setStatus(const std::string &label)
{
	if(mStatusLabel != NULL) {
		mStatusLabel->setString(label.c_str());
	} else {
		log("mStatusLabel is null??");
	}
}

void TTTUILayer::handlePlayClicked()
{
	log("play is clicked");
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	changeToGame();
}

void TTTUILayer::handleBoardState(TTTBoard::State state)
{
	switch (state) {
		// Handling of ending case
		case TTTBoard::State::DrawGame:
		case TTTBoard::State::Player1Win:
		case TTTBoard::State::Player2Win:
		{
			changeToEnd(state);
			break;
		}
		
		case TTTBoard::State::Player1:
		{
			setStatus("Player 1 Turn");
			break;
		}
			
		case TTTBoard::State::Player2:
		{
			setStatus("Player 2 Turn");
			break;
		}
	}
}

#pragma mark - 
#pragma mark State Logic
void TTTUILayer::changeToStart()
{
	setStatus("Press 'play' button to start");
	
	// No allow to play yet
	mBoard->reset();
	mBoard->setEnable(false);
}

void TTTUILayer::changeToGame()
{
	setStatus("Player 1 Turn");
	
	mBoard->reset();	// Start with player 1
	mBoard->setEnable(true);
	
	mPlayerButton->setVisible(false);
}

void TTTUILayer::changeToEnd(TTTBoard::State state)
{
	switch (state) {
		// Handling of ending case
		case TTTBoard::State::DrawGame:
		{
			setStatus("Draw Game!!!");
			SimpleAudioEngine::getInstance()->playBackgroundMusic(kSoundDraw);
			break;
		}
			
		case TTTBoard::State::Player1Win:
		{
			setStatus("Player 1 WIN!");
			SimpleAudioEngine::getInstance()->playBackgroundMusic(kSoundWin);
			break;
		}
			
		case TTTBoard::State::Player2Win:
		{
			setStatus("Player 2 WIN!");
			SimpleAudioEngine::getInstance()->playBackgroundMusic(kSoundWin);
			break;
		}
			
		default: {
			return;		// Other cases are somthing wrong
		}
	}
	
	// Make the player button available again
	mPlayerButton->setVisible(true);
	mPlayerButton->setEnabled(true);
	mPlayerButton->setTitleText("Play Again");
	
	//	setStatus("Game Started");
}

