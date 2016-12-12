#include "HelloWorldScene.h"
#include "GameOverScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	scene->getPhysicsWorld()->setGravity(Vec2(0, -1000));

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
    {
        return false;
    }
    
	visibleSize = Director::getInstance()->getVisibleSize();
	time = 0;
	
	//gcs.insert(0, GameController::create(this, 180));
	switch (UserDefault::getInstance()->getIntegerForKey("level")){

	case 1:
		gcs.insert(0, GameController::create(this, 20, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));

		gcs.insert(0, GameController::create(this, 200, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));
		break;
	case 2:
		gcs.insert(0, GameController::create(this, 20, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));

		gcs.insert(0, GameController::create(this, 200, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));

		gcs.insert(0, GameController::create(this, 380, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));
		break;
	case 3:
		gcs.insert(0, GameController::create(this, 20, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));

		gcs.insert(0, GameController::create(this, 180, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));

		gcs.insert(0, GameController::create(this, 340, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));

		gcs.insert(0, GameController::create(this, 500, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));
		break;
	case 4:
		gcs.insert(0, GameController::create(this, 0, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));

		gcs.insert(0, GameController::create(this, 130, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));

		gcs.insert(0, GameController::create(this, 260, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));

		gcs.insert(0, GameController::create(this, 390, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));

		gcs.insert(0, GameController::create(this, 520, UserDefault::getInstance()->getStringForKey("hero", "Hero.json")));
		break;
	}

	scheduleUpdate();

	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact & contact){
		this->unscheduleUpdate();

		if (UserDefault::getInstance()->getBoolForKey("sound"))
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("crash.mp3");
		}
		UserDefault::getInstance()->setStringForKey("time", times);
		Director::getInstance()->pushScene(GameOver::createScene()); 
		
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [this](Touch * t, Event * e){

		for (auto it = gcs.begin(); it != gcs.end(); it++)
		{
			if ((*it)->hitTestPoint(t->getLocation()))
			{
				(*it)->onUserTouch();
				break;
			}
		}

		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

	
	

	return true;
}

void HelloWorld::update(float dt){

	for (auto it = gcs.begin(); it != gcs.end(); it++)
	{
		(*it)->onUpdate(dt);
	}

	time++;

	
	double t = time / 1000.000;
	
	char temp[16];
	sprintf(temp, "%.3f", t);
	times = temp;

	removeChildByTag(1);
	
	auto timeShow = LabelTTF::create(times+"\"", "Arial-BoldMT", 25);
	timeShow->setTag(1);
	timeShow->setFontFillColor(Color3B::BLACK);
	timeShow->setPosition(visibleSize.width - timeShow->getContentSize().width/2, visibleSize.height - timeShow->getContentSize().height);
	addChild(timeShow);

}