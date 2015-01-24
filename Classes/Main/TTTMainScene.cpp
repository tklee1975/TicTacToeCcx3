//
//  TTTMainScene.cpp
//  TicTacToe
//
//  Created by Ken Lee on 23/1/15.
//
//

#include "TTTMainScene.h"
#include "TTTUILayer.h"

TTTMainScene *TTTMainScene::createScene()
{
	// 'scene' is an autorelease object
	TTTMainScene *scene = TTTMainScene::create();
	
	return scene;
}

TTTMainScene::TTTMainScene()
: mGameLayer(NULL)
{
	
}

TTTMainScene::~TTTMainScene()
{
	
}

bool TTTMainScene::init()
{
	bool flag;
	
	flag = Scene::init();
	if(flag == false) {
		return flag;
	}
	
	// Add the gameLayer
	TTTUILayer *layer = TTTUILayer::create();
	addChild(layer);
	mGameLayer = layer;

	
	return flag;
}