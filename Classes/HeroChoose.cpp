#include "HeroChoose.h"
#include "FlashTool.h"


HeroChoose* HeroChoose::create(std::string jsonFile){

	auto _ins = new HeroChoose();
	_ins->init(jsonFile);
	_ins->autorelease();
	return _ins;
}

bool HeroChoose::init(std::string jsonFile){

	Sprite::init();

	Size s = Size(44, 52);

	runAction(RepeatForever::create(FlashTool::readJsonSpriteSheet(jsonFile, 0.2f)));

	setContentSize(s);
	
	return true;
}
