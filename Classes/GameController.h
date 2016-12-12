#pragma once

#include "cocos2d.h"
#include "Edge.h"
#include "Hero.h"
#include "Block.h"
#include "PhysicHero.h"
USING_NS_CC;

class GameController:public Ref
{
private:
	Layer * _layer;
	float _positionY;
	std::string _jsonFile;

	Size visibleSize;
	int currentFrameIndex;
	int nextFrameCount;
	Edge * edge;
	PhysicHero * hero;

private:
	void resetFrames();
	void addBlock();

public:
	virtual bool init(Layer *layer, float positionY, std::string jsonFile);

	void onUpdate(float dt);

	bool hitTestPoint(Vec2 point);

	void onUserTouch();

	static GameController* create(Layer *layer, float positionY, std::string jsonFile);
};

