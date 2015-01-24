//
//  TTTChess.cpp
//  TicTacToe
//
//  Created by Ken Lee on 11/1/15.
//
//

#include "TTTChess.h"


TTTChess::TTTChess()
{
	
}

TTTChess::~TTTChess()
{
	// Destructor
}


const char *TTTChess::getImageName(Type type)
{
	switch (type) {
		case Type::CIRCLE:		return "icon-o.png";
		case Type::CROSS:		return "icon-x.png";
		default:				return NULL;
	}
	
}

void TTTChess::setType(Type type)
{
	const char *imgName = getImageName(type);
	
	
	if(imgName == NULL) {
		setVisible(false);
		return;
	}
	
	setVisible(true);
	setTexture(imgName);
}


