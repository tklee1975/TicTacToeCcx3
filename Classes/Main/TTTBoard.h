//
//  TTTBoard.h
//  TicTacToe
//
//  Created by Ken Lee on 10/1/15.
//
//

#ifndef __TicTacToe__TTTBoard__
#define __TicTacToe__TTTBoard__

#include <stdio.h>
#include "cocos2d.h"
#include "TTTType.h"

class TTTChess;
class TTTBoardLogic;

USING_NS_CC;

class TTTBoard
: public LayerColor
{
public:
	enum class State {
		Player1,
		Player2,
		Player1Win,
		Player2Win,
		DrawGame,
	};
	
	typedef std::function<void(Ref*, TTTBoard::State)> TTTBoardCallback;
public:
	bool initWithSize(const float size);
	
	
	static TTTBoard *createWithSize(const float size);
	
	virtual void onEnter();
	virtual void onExit();
	
	void changeState(State state);
	void setEnable(bool flag);
	void reset();
	void setBoardListener(const TTTBoardCallback &callback);
	
private:
	// UI Composition
	void addGrids();
	void addVerticalGrids();
	void addHorizontalGrids();
	
	
	// Touch handling
	void setupTouchListener();
	
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	
	// coordinate conversion
	Vec2 getGridPosition(const Vec2 &location);
	Vec2 getNodePosition(const Vec2 &gridPos);;
	
	// the validate the moves
	bool containChess(const Vec2 &position);
	TTTChess *addChess(const Vec2 &position);
	bool isValidPos(const Vec2 &position);

	void moveChess(TTTChess *chess, const Vec2 &position);
	void changePlayer();
	void handleMoveEnd();
private:
	int mGrid;			// number of grid
	float mGridSize;	// length of the grid
	bool mEnable;
	TTTBoardCallback mGameEndListener;
	
	int mCurrentPlayer;		// 0 - Unknown 1 - Player1  2 - Player2
	
	State mState;
	TTTBoardLogic *mLogic;
	
	TTTChess *mPlacingChess;
	TTTChess *mChessArray[kNumGrid][kNumGrid];
};

#endif /* defined(__TicTacToe__TTTBoard__) */
