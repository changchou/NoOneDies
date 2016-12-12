#include "ChooseHero.h"


USING_NS_CC;

Scene* ChooseHero::createScene(){

	auto scene = Scene::create();
	auto l = ChooseHero::create();
	scene->addChild(l);
	return scene;
}


bool ChooseHero::init(){

	LayerColor::initWithColor(Color4B::WHITE);

	visibleSize = Director::getInstance()->getVisibleSize();

	auto top = Sprite::create("choosetop.png");
	addChild(top);
	top->setPosition(visibleSize.width / 2, visibleSize.height * 4 / 5);

	auto h1 = HeroChoose::create("Hero.json");
	addChild(h1);
	h1->setPosition(h1->getContentSize().width * 2, visibleSize.height * 3 / 5);

	auto h2 = HeroChoose::create("Her.json");
	addChild(h2);
	h2->setRotationY(180);
	h2->setPosition(visibleSize.width - h2->getContentSize().width * 2, visibleSize.height * 3 / 5);

	auto ground1 = Sprite::create();
	ground1->setColor(Color3B(0, 0, 0));
	ground1->setTextureRect(Rect(0, 0, visibleSize.width, 3));
	ground1->setPosition(visibleSize.width / 2, h1->getPositionY()-h1->getContentSize().height/2);
	addChild(ground1);


	auto hero1 = HeroChoose::create("Hero.json");
	auto hero2 = HeroChoose::create("Her.json");
	auto hero3 = HeroChoose::create("Hero.json");
	auto hero4 = HeroChoose::create("Her.json");
	auto hero5 = HeroChoose::create("Hero.json");
	auto ground = Sprite::create();
	ground->setColor(Color3B(0, 0, 0));
	ground->setTextureRect(Rect(0, 0, visibleSize.width, 3));
	switch (UserDefault::getInstance()->getIntegerForKey("level"))
	{
	case 1:

		addChild(hero1);
		hero1->setPosition(visibleSize.width / 3, visibleSize.height * 2 / 5);
		
		addChild(hero2);
		hero2->setPosition(visibleSize.width * 2 / 3, visibleSize.height * 2 / 5);
		
		addChild(ground);
		ground->setPosition(visibleSize.width / 2, hero1->getPositionY() - hero1->getContentSize().height / 2);
		
		break;
	case 2:
		
		addChild(hero1);
		hero1->setPosition(visibleSize.width / 4, visibleSize.height * 2 / 5);
		
		addChild(hero2);
		hero2->setPosition(visibleSize.width / 2, visibleSize.height * 2 / 5);
		
		addChild(hero3);
		hero3->setPosition(visibleSize.width * 3 / 4, visibleSize.height * 2 / 5);

		addChild(ground);
		ground->setPosition(visibleSize.width / 2, hero1->getPositionY() - hero1->getContentSize().height / 2);
		
		break;
	case 3:
		
		addChild(hero1);
		hero1->setPosition(visibleSize.width / 5, visibleSize.height * 2 / 5);
		
		addChild(hero2);
		hero2->setPosition(visibleSize.width * 2 / 5, visibleSize.height * 2 / 5);
		
		addChild(hero3);
		hero3->setPosition(visibleSize.width * 3 / 5, visibleSize.height * 2 / 5);
		
		addChild(hero4);
		hero4->setPosition(visibleSize.width * 4 / 5, visibleSize.height * 2 / 5);

		addChild(ground);
		ground->setPosition(visibleSize.width / 2, hero1->getPositionY() - hero1->getContentSize().height / 2);
		
		break;
	case 4:
		
		addChild(hero1);
		hero1->setPosition(visibleSize.width / 6, visibleSize.height * 2 / 5);
		
		addChild(hero2);
		hero2->setPosition(visibleSize.width * 2 / 6, visibleSize.height * 2 / 5);
		
		addChild(hero3);
		hero3->setPosition(visibleSize.width * 3 / 6, visibleSize.height * 2 / 5);
		
		addChild(hero4);
		hero4->setPosition(visibleSize.width * 4 / 6, visibleSize.height * 2 / 5);
		
		addChild(hero5);
		hero5->setPosition(visibleSize.width * 5 / 6, visibleSize.height * 2 / 5);

		addChild(ground);
		ground->setPosition(visibleSize.width / 2, hero1->getPositionY() - hero1->getContentSize().height / 2);
		
		break;

	}

	auto label1 = LabelTTF::create("BACK", "Arial-BoldMT", 30);
	label1->setFontFillColor(Color3B::BLACK);
	label1->setPosition(visibleSize.width / 3, visibleSize.height * 1 / 5);
	addChild(label1);

	auto label2 = LabelTTF::create("START", "Arial-BoldMT", 30);
	label2->setFontFillColor(Color3B::BLACK);
	label2->setPosition(visibleSize.width * 2 / 3, visibleSize.height * 1 / 5);
	addChild(label2);


	auto h1Listener = EventListenerTouchOneByOne::create();
	h1Listener->onTouchBegan = [h1,h2](Touch *t, Event *e){

		if (h1->getBoundingBox().containsPoint(t->getLocation())){
			h1->setScale(1.5);
			h2->setScale(1);
			UserDefault::getInstance()->setStringForKey("hero", "Hero.json");
			if (UserDefault::getInstance()->getBoolForKey("sound"))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("choose.mp3");
			}
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(h1Listener, h1);

	auto h2Listener = EventListenerTouchOneByOne::create();
	h2Listener->onTouchBegan = [h1, h2](Touch *t, Event *e){

		if (h2->getBoundingBox().containsPoint(t->getLocation())){
			h2->setScale(1.5);
			h1->setScale(1);
			UserDefault::getInstance()->setStringForKey("hero", "Her.json");
			if (UserDefault::getInstance()->getBoolForKey("sound"))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("choose.mp3");
			}
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(h2Listener, h2);

	auto backListener = EventListenerTouchOneByOne::create();
	backListener->onTouchBegan = [label1](Touch *t, Event *e){

		if (label1->getBoundingBox().containsPoint(t->getLocation())){

			if (UserDefault::getInstance()->getBoolForKey("sound"))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
			}
			Director::getInstance()->popScene();
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(backListener, label1);


	auto startListener = EventListenerTouchOneByOne::create();
	startListener->onTouchBegan = [label2](Touch *t, Event *e){

		if (label2->getBoundingBox().containsPoint(t->getLocation())){
			
			if (UserDefault::getInstance()->getBoolForKey("sound"))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
			}
				Director::getInstance()->pushScene(HelloWorld::createScene());
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(startListener, label2);

	auto listener = EventListenerKeyboard::create();
	listener->onKeyReleased = [](EventKeyboard::KeyCode code, Event *e){

		switch (code)
		{
		case EventKeyboard::KeyCode::KEY_BACKSPACE:
		case EventKeyboard::KeyCode::KEY_BACK:
		case EventKeyboard::KeyCode::KEY_HOME:
			UserDefault::getInstance()->setBoolForKey("sound", true);
			UserDefault::getInstance()->setStringForKey("hero", "Hero.json");
			Director::getInstance()->end();
			break;
		default:
			break;
		}
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	return true;
}