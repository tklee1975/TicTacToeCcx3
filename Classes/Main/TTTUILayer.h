
//
//  TTTUILayer.h
//  TicTacToe
//
//  Created by Ken Lee on 17/1/15.
//
//

#ifndef __TicTacToe__TTTUILayer__
#define __TicTacToe__TTTUILayer__

#include <stdio.h>

#include <stdio.h>
#include "cocos2d.h"
#include "TTTType.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"


#include "TTTBoard.h"

USING_NS_CC_EXT;
USING_NS_CC;
using namespace cocos2d::ui;



class TTTUILayer : public Layer
{
public:
	bool init();
	
	static TTTUILayer *create();
	
	Text *mStatusLabel;
	Button *mPlayerButton;
	
private:
	void setupBoard(Node *boardNode);
	void setupUI(Node *mainPanel);
	
	void setStatus(const std::string &label);
	
	void changeToStart();
	void changeToGame();
	void changeToEnd(TTTBoard::State state);
	
	void handlePlayClicked();
	void handleBoardState(TTTBoard::State state);
	
private:
	TTTBoard *mBoard;
};

#endif /* defined(__TicTacToe__TTTUILayer__) */
