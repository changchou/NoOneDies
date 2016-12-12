#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

class GameStartScene :public LayerColor{


private:

	Size visibleSize;
	
public:

	static Scene* createScene();

	virtual bool init();

	void menuCloseCallback(Ref* pSender);


	CREATE_FUNC(GameStartScene);

	
};