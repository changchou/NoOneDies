#pragma once

#include "cocos2d.h"

USING_NS_CC;

class PhysicHero :public Sprite
{
public:
	virtual bool init(std::string jsonFile);

	static PhysicHero* create(std::string jsonFile);
};
