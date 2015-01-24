//
//  TTTBoardLogic.cpp
//  TicTacToe
//
//  Created by Ken Lee on 20/1/15.
//
//

#include "TTTBoardLogic.h"
#include "cocos2d.h"

USING_NS_CC;

TTTBoardLogic::TTTBoardLogic()
{
	reset();
}

void TTTBoardLogic::reset()
{
	for(int i=0; i<kNumGrid; i++) {
		for(int j=0; j<kNumGrid; j++) {
			mChessArray[i][j] = 0;
		}
	}
}

void TTTBoardLogic::placeChess(int player, int x, int y)
{
	if(x < 0 || x >= kNumGrid) {
		log("placeChess: invalid x (%d)", x);
		return;
	}

	if(y < 0 || y >= kNumGrid) {
		log("placeChess: invalid y (%d)", y);
		return;
	}
	
	mChessArray[x][y] = player;
}

TTTBoardLogic::Result TTTBoardLogic::check()
{
	Result result;
	
	result = checkForHorizontalLine();
	if(result != Result::NotYet) {
		return result;
	}
	
	result = checkForVerticalLine();
	if(result != Result::NotYet) {
		return result;
	}
	
	result = checkForDiagonal();
	if(result != Result::NotYet) {
		return result;
	}
	
	return isAllPlaced() ? Result::DrawGame : Result::NotYet;
}


#pragma mark - Checking
TTTBoardLogic::Result TTTBoardLogic::checkForVerticalLine()
{
	Result result = Result::NotYet;
	
	// for x = 0 -> 2
	for(int x=0; x<kNumGrid; x++) {
		int firstValue = mChessArray[x][0];	//
		
		if(firstValue == 0) {
			continue;	// check next column
		}
		
		bool hasMatch = true;
		for(int y=1; y<kNumGrid; y++) {
			if(mChessArray[x][y] != firstValue) {
				hasMatch = false;
				break;
			}
		}
		
		//
		if(hasMatch) {
			return firstValue == 1 ? Result::P1Win : Result::P2Win;
		}
	}
	
	return result;
}

TTTBoardLogic::Result TTTBoardLogic::checkForHorizontalLine()
{
	Result result = Result::NotYet;
	
	// for y = 0 -> 2
	for(int y=0; y<kNumGrid; y++) {
		int firstValue = mChessArray[0][y];	//
		
		if(firstValue == 0) {
			continue;	// check next row
		}
		
		bool hasMatch = true;
		for(int x=1; x<kNumGrid; x++) {
			// log("x=%d y=%d firstV=%d thisV=%d", x, y, firstValue, mChessArray[x][y]);
			if(mChessArray[x][y] != firstValue) {
				//log("break!!");
				hasMatch = false;
				break;
			}
		}
		
		//
		if(hasMatch) {
			return firstValue == 1 ? Result::P1Win : Result::P2Win;
		}
	}
	
	return result;
}

TTTBoardLogic::Result TTTBoardLogic::checkForDiagonal()
{
	int firstValue;
	bool anyMatch;
	// Check from Top to Down
	firstValue = mChessArray[0][0];
	if(firstValue != 0) {
		anyMatch = true;
		
		for(int i=1; i<kNumGrid; i++) {
			if(firstValue != mChessArray[i][i]) {
				anyMatch = false;
				break;
			}
		}
		
		if(anyMatch) {
			return firstValue == 1 ? Result::P1Win : Result::P2Win;
		}
	}
	
	
	// Check from Down to Top
	firstValue = mChessArray[0][kNumGrid-1];
	if(firstValue != 0) {
		anyMatch = true;
		
		for(int x=1; x<kNumGrid; x++) {
			int y=kNumGrid-x-1;
			
			if(firstValue != mChessArray[x][y]) {
				anyMatch = false;
				break;
			}
		}
		
		if(anyMatch) {
			return firstValue == 1 ? Result::P1Win : Result::P2Win;
		}
	}
	
	return Result::NotYet;
}

bool TTTBoardLogic::isAllPlaced()
{
	for(int i=0; i<kNumGrid; i++) {
		for(int j=0; j<kNumGrid; j++) {
			if(mChessArray[i][j] == 0) {
				return false;
			}
		}
	}
	
	return true;
}

void TTTBoardLogic::info(std::string &result)
{
	char str[100] = "";
	
	result = "";
	
	for(int y=0; y<kNumGrid; y++) {
		for(int x=0; x<kNumGrid; x++) {
			sprintf(str, "%s%d ", str, mChessArray[x][y]);
		}
		sprintf(str, "%s\n", str);
	}
	
	result.append(str);
}