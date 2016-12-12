#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

USING_NS_CC;

class GameOver :public LayerColor{

private:
	Size visibleSize;

public:
	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(GameOver);

};