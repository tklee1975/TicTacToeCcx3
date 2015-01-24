//
//  TTTMainScene.h
//  TicTacToe
//
//  Created by Ken Lee on 23/1/15.
//
//

#ifndef __TicTacToe__TTTMainScene__
#define __TicTacToe__TTTMainScene__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class TTTUILayer;

class TTTMainScene : public Scene
{
public:
	TTTMainScene();
	virtual ~TTTMainScene();
	
	virtual bool init();
	
	// Method to create
	static TTTMainScene *createScene();	
	CREATE_FUNC(TTTMainScene);
private:
	TTTUILayer *mGameLayer;
};



//TTTMain

#endif /* defined(__TicTacToe__TTTMainScene__) */
