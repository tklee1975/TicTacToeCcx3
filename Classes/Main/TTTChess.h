//
//  TTTChess.h
//  TicTacToe
//
//  Created by Ken Lee on 11/1/15.
//
//

#ifndef __TicTacToe__TTTChess__
#define __TicTacToe__TTTChess__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class TTTChess : public Sprite
{
public:	// enum
	enum class Type {
		EMPTY,
		CIRCLE,
		CROSS
	};
	
public:
	TTTChess();
	virtual ~TTTChess();
	
	void setType(Type type);
	
	CREATE_FUNC(TTTChess);
	
private:
	const char *getImageName(Type type);
};

#endif /* defined(__TicTacToe__TTTChess__) */
