#include "Block.h"


bool Block::init(){

	Sprite::init();

	Size s = Size((rand() % 20) + 5, (rand() % 30) + 10);
	Size visibleSize = Director::getInstance()->getVisibleSize();

	setContentSize(s);
	setPhysicsBody(PhysicsBody::createBox(s));
	setTextureRect(Rect(0, 0, s.width, s.height));
	setColor(Color3B(0, 0, 0));

	setPositionX(visibleSize.width);
	scheduleUpdate();

	getPhysicsBody()->setDynamic(false);

	getPhysicsBody()->setContactTestBitmask(1);

	return true;
}

void Block::update(float dt){
	this->setPositionX(getPositionX() - 4);

	if (getPositionX() < 0)
	{
		unscheduleUpdate();
		removeFromParent();
	}
}