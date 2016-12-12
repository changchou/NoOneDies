#pragma once

#include "cocos2d.h"

USING_NS_CC;

class HeroChoose :public Sprite
{
public:
	virtual bool init(std::string jsonFile);

	static HeroChoose* create(std::string jsonFile);
};
