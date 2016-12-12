#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "HeroChoose.h"
#include "HelloWorldScene.h"
#include "GameStartScene.h"


USING_NS_CC;

class ChooseHero :public LayerColor{

private:

	Size visibleSize;

public:

	static Scene* createScene();


	virtual bool init();


	CREATE_FUNC(ChooseHero);


};