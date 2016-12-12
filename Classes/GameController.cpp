#include "GameController.h"


USING_NS_CC;

GameController* GameController::create(Layer *layer, float positionY, std::string jsonFile){

	auto _ins = new GameController();
	_ins->init(layer, positionY,jsonFile);
	_ins->autorelease();
	return _ins;
}

bool GameController::init(Layer *layer, float positionY, std::string jsonFile){

	_layer = layer;
	_positionY = positionY;
	_jsonFile = jsonFile;
	visibleSize = Director::getInstance()->getVisibleSize();

	//add Edge
	edge = Edge::create(); 
	edge->setAnchorPoint(Vec2(0.5, 0.5));
	edge->setPosition(visibleSize.width / 2, visibleSize.height / 2 + positionY);
	edge->setContentSize(visibleSize);
	layer->addChild(edge);

	//add Ground
	auto ground = Sprite::create();
	ground->setColor(Color3B(0, 0, 0));
	ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
	ground->setPosition(visibleSize.width / 2, 1.5 + positionY);
	layer->addChild(ground);

	//add Hero
	hero = PhysicHero::create(jsonFile);
	hero->setScale(0.6);
	hero->setPosition(50, hero->getContentSize().height / 2 + positionY);
	layer->addChild(hero);

	resetFrames();

	return true;
}

void GameController::resetFrames(){
	currentFrameIndex = 0;
	nextFrameCount = (rand() % 120) + 100;
}

void GameController::addBlock(){
	
	auto block = Block::create();
	_layer->addChild(block);
	block->setPositionY(block->getContentSize().height / 2 + _positionY);

}

void GameController::onUpdate(float dt){
	currentFrameIndex++;

	if (currentFrameIndex >= nextFrameCount)
	{
		resetFrames();

		addBlock();
	}

}

bool GameController::hitTestPoint(Vec2 point){

	return edge->getBoundingBox().containsPoint(point);
	
}

void GameController::onUserTouch(){
	hero->getPhysicsBody()->setVelocity(Vec2(0, 400));
}