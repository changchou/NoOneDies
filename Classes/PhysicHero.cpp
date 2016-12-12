#include "PhysicHero.h"
#include "FlashTool.h"


PhysicHero* PhysicHero::create(std::string jsonFile){

	auto h = new PhysicHero();
	h->init(jsonFile);
	h->autorelease();
	return h;
}

bool PhysicHero::init(std::string jsonFile){

	Sprite::init();

	Size s = Size(44, 52);

	runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet(jsonFile, 0.2f)));

	setContentSize(s);
	setPhysicsBody(PhysicsBody::createBox(s));

	getPhysicsBody()->setRotationEnable(false);

	getPhysicsBody()->setContactTestBitmask(1);

	return true;
}