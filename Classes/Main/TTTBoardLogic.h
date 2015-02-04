//
//  TTTBoardLogic.h
//  TicTacToe
//
//  Created by Ken Lee on 20/1/15.
//
//

#ifndef __TicTacToe__TTTBoardLogic__
#define __TicTacToe__TTTBoardLogic__

#include <stdio.h>
#include <string>
#include "TTTType.h"

class TTTBoardLogic
{
public:
	enum class Result {
		NotYet = 0,
		P1Win,
		P2Win,
		DrawGame,
	};

public:
	TTTBoardLogic();
	
	void reset();
	void placeChess(int player, int x, int y);
	Result check();			// Chess for result
	void info(std::string &result);
	
private:
	Result checkForVerticalLine();
	Result checkForHorizontalLine();
	Result checkForDiagonal();
	bool isAllPlaced();			// if
	
private:
	int mChessArray[kNumGrid][kNumGrid];		// 0 - not placed, 1 - player1 , 2 - player2
};

#endif /* defined(__TicTacToe__TTTBoardLogic__) */
