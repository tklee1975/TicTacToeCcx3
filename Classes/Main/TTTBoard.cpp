//
//  TTTBoard.cpp
//  TicTacToe
//
//  Created by Ken Lee on 10/1/15.
//
//

#include "TTTBoard.h"
#include "TTTStyle.h"
#include "TTTChess.h"
#include "TTTBoardLogic.h"

TTTBoard *TTTBoard::createWithSize(const float size)
{
	TTTBoard *board = new TTTBoard();
	bool isOkay = board->initWithSize(size);
	
	if(isOkay == false) {
		return NULL;
	}
	
	
	
	return board;
}

// on "init" you need to initialize your instance
bool TTTBoard::initWithSize(const float size)
{
	//////////////////////////////
	// 1. super init first
	if ( !LayerColor::initWithColor(TTT_BOARD_BG, size, size))
	{
		return false;
	}
	
	mGrid = kNumGrid;
	mGridSize = getContentSize().width / mGrid;
	
	// Create the Grid Line
	addGrids();
	
	mLogic = new TTTBoardLogic();
	mPlacingChess = NULL;
	
	return true;
}

void TTTBoard::onEnter()
{
	log("TTTBoard: onEnter");
	
	LayerColor::onEnter();
	
	setupTouchListener();
}

void TTTBoard::onExit()
{
	log("TTTBoard: onExit");
	
	this->getEventDispatcher()->removeEventListenersForTarget(this);
	
	LayerColor::onExit();
}

void TTTBoard::changeState(State state)
{
	mState = state;
}

void TTTBoard::setupTouchListener()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	
	listener->onTouchBegan = CC_CALLBACK_2(TTTBoard::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(TTTBoard::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(TTTBoard::onTouchEnded, this);
	
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void TTTBoard::addGrids()
{
	addVerticalGrids();
	addHorizontalGrids();
}

void TTTBoard::addVerticalGrids()
{
	Color4B color = TTT_LINE_COLOR;
	
	int numLine = mGrid - 1;
	float lineThick = 6;
	float lineHeight = getContentSize().height;
	float x = (mGridSize - lineThick/2);
	
	Point pos = Point(x, 0);
	
	for(int i=0; i<numLine; i++) {
		LayerColor *line = LayerColor::create(color, lineThick, lineHeight);
		line->setPosition(pos);
		addChild(line);
		
		pos.x += mGridSize;
	}
}

void TTTBoard::addHorizontalGrids()
{
	Color4B color = TTT_LINE_COLOR;
	
	int numLine = mGrid - 1;
	float lineThick = 6;
	float lineWidth = getContentSize().width;
	float y = (mGridSize - lineThick/2);
	
	Point pos = Point(0, y);
	
	for(int i=0; i<numLine; i++) {
		LayerColor *line = LayerColor::create(color, lineWidth, lineThick);
		line->setPosition(pos);
		addChild(line);
		
		pos.y += mGridSize;
	}
}

#pragma mark -
#pragma mark Add chess 
bool TTTBoard::containChess(const Vec2 &position)
{
	int x = position.x;
	int y = position.y;

	return mChessArray[x][y] != NULL;
}


TTTChess *TTTBoard::addChess(const Vec2 &position)
{
	Vec2 nodePos = getNodePosition(position);
	
	TTTChess::Type type = (mCurrentPlayer == 1) ?
							TTTChess::Type::CIRCLE : TTTChess::Type::CROSS;
	
	//Sprite *sprite = Sprite::create()
	TTTChess *chess = TTTChess::create();
	chess->setType(type);
	chess->setPosition(nodePos);
	
	addChild(chess);
	
	return chess;
}

void TTTBoard::moveChess(TTTChess *chess, const Vec2 &position)
{
	if(chess == NULL) {
		return;
	}
	
	Vec2 nodePos = getNodePosition(position);
	
	chess->setPosition(nodePos);
}

bool TTTBoard::isValidPos(const Vec2 &position)
{
	int x = position.x;
	int y = position.y;
	
	if(x < 0 || x >= mGrid) {
		return false;
	}
	
	if(y < 0 || y >= mGrid) {
		return false;
	}
	
	return containChess(position) == false;
}

#pragma mark -
#pragma mark Utility 
Vec2 TTTBoard::getNodePosition(const Vec2 &gridPos)
{
	int x = gridPos.x * mGridSize + mGridSize/2;
	int y = gridPos.y * mGridSize + mGridSize/2;
	
	return Vec2(x, y);
}

Vec2 TTTBoard::getGridPosition(const Vec2 &location)
{
	int x = location.x / mGridSize;
	int y = location.y / mGridSize;
	
	return Vec2(x, y);
}

#pragma mark -
#pragma mark Touches
bool TTTBoard::onTouchBegan(Touch *touch, Event *event)
{
	if(mEnable == false) {
		return false;
	}
	
	CCLOG("TTTBoard::onTouchBegan id = %d, x = %f, y = %f", touch->getID(),
		  touch->getLocation().x, touch->getLocation().y);
	Vec2 localPoint = convertToNodeSpace(touch->getLocation());
	Vec2 gridPosition = getGridPosition(localPoint);
	
	log("localPoint: %f,%f  gridPos: %f,%f", localPoint.x, localPoint.y, gridPosition.x, gridPosition.y);
	
	if(isValidPos(gridPosition) == false) {
		log("onTouchBegan: invalid pos!");
		// Say something to
		return false;
	}
	
	TTTChess *chess = addChess(gridPosition);
	mPlacingChess = chess;
	
	return true;
}


void TTTBoard::onTouchMoved(Touch *touch, Event *event)
{
	Vec2 localPoint = convertToNodeSpace(touch->getLocation());
	Vec2 gridPosition = getGridPosition(localPoint);
	
	if(isValidPos(gridPosition) == false) {
		return;
	}
	
	if(mPlacingChess != NULL) {
		moveChess(mPlacingChess, gridPosition);
	}
}

void TTTBoard::changePlayer()
{
	if(mCurrentPlayer == 1) {
		mCurrentPlayer = 2;
	} else {
		mCurrentPlayer = 1;
	}
}

void TTTBoard::onTouchEnded(Touch *touch, Event *event)
{
	Vec2 localPoint = convertToNodeSpace(touch->getLocation());
	Vec2 gridPosition = getGridPosition(localPoint);
	
	int x = gridPosition.x;
	int y = gridPosition.y;
	
	// Placing the new move
	mChessArray[x][y] = mPlacingChess;
	
	// Playing the chess
	mLogic->placeChess(mCurrentPlayer, x, y);
	
	
	// Checking the result
	handleMoveEnd();
	
}

void TTTBoard::handleMoveEnd()
{
	TTTBoardLogic::Result result = mLogic->check();
	
	State returnState;
	
	
	std::string boardInfo;
	mLogic->info(boardInfo);
	log("debug: board:\n%s\n", boardInfo.c_str());
	log("debug: gameResult=%d", result);
	
	bool canContinue = false;
	
	if(result == TTTBoardLogic::Result::NotYet) {
		// Still don't have any winner
		
		// change to next player
		changePlayer();
		
		// Tell the caller
		returnState = mCurrentPlayer == 1 ? State::Player1 : State::Player2;
		
		canContinue = true;
	} else if(result == TTTBoardLogic::Result::P1Win) {
		returnState = State::Player1Win;
	} else if(result == TTTBoardLogic::Result::P2Win) {
		returnState = State::Player2Win;
	} else {
		returnState = State::DrawGame;
	}
	
	if(mGameEndListener != nullptr) {
		mGameEndListener(this, returnState);
	}
	
	if(canContinue == false) {
		this->setEnable(false);
	}
	
}


void TTTBoard::setEnable(bool flag)
{
	mEnable = flag;
}

void TTTBoard::reset()
{
	mCurrentPlayer = 1;
	
	mPlacingChess = NULL;
	
	// Clean up
	for(int i=0; i<mGrid; i++) {
		for(int j=0; j<mGrid; j++) {
			auto node = mChessArray[i][j];
			if(node != NULL) {
				node->removeFromParent();
			}
			mChessArray[i][j] = NULL;
		}
	}
	
	mLogic->reset();
}


void TTTBoard::setBoardListener(const TTTBoardCallback &callback)
{
	mGameEndListener = callback;
}