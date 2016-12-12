#include "GameStartScene.h"
#include "ChooseHero.h"

USING_NS_CC;

Scene* GameStartScene::createScene(){

	auto scene = Scene::create();
	auto l = GameStartScene::create();
	scene->addChild(l);
	return scene;
}

bool GameStartScene::init(){
	LayerColor::initWithColor(Color4B::WHITE);

	visibleSize = Director::getInstance()->getVisibleSize();
	
	auto top = Sprite::create("top.png");
	addChild(top);
	top->setPosition(visibleSize.width / 2, visibleSize.height*6/7);


	auto soundOnItem = MenuItemImage::create(
		"sound_on.png",
		"sound_on.png");

	auto soundCloseItem = MenuItemImage::create(
		"sound_off.png",
		"sound_off.png");

	auto soundMenu = MenuItemToggle::createWithCallback(CC_CALLBACK_1(GameStartScene::menuCloseCallback, this),
		soundOnItem, soundCloseItem, NULL);
	soundMenu->setPosition(Vec2(visibleSize.width - soundMenu->getContentSize().width,
		visibleSize.height - soundMenu->getContentSize().height));
	auto menu = Menu::create(soundMenu, NULL);
	addChild(menu);
	menu->setPosition(Vec2::ZERO);


	auto level1 = Sprite::create("level1.png");
	addChild(level1);
	level1->setPosition(visibleSize.width / 2, visibleSize.height * 5 / 7);

	auto level1Listener = EventListenerTouchOneByOne::create();
	level1Listener->onTouchBegan = [level1](Touch *t, Event *e){
		if (level1->getBoundingBox().containsPoint(t->getLocation()))
		{
			
			if (UserDefault::getInstance()->getBoolForKey("sound"))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
			}
			UserDefault::getInstance()->setIntegerForKey("level",1);
			Director::getInstance()->pushScene(ChooseHero::createScene());
			
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(level1Listener, level1);


	auto level2 = Sprite::create("level2.png");
	addChild(level2);
	level2->setPosition(visibleSize.width / 2, visibleSize.height * 4 / 7);

	auto level2Listener = EventListenerTouchOneByOne::create();
	level2Listener->onTouchBegan = [level2](Touch *t, Event *e){
		if (level2->getBoundingBox().containsPoint(t->getLocation()))
		{
			if (UserDefault::getInstance()->getBoolForKey("sound"))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
			}
			UserDefault::getInstance()->setIntegerForKey("level", 2);
			Director::getInstance()->pushScene(ChooseHero::createScene());
		}


		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(level2Listener, level2);


	auto level3 = Sprite::create("level3.png");
	addChild(level3);
	level3->setPosition(visibleSize.width / 2, visibleSize.height * 3 / 7);

	auto level3Listener = EventListenerTouchOneByOne::create();
	level3Listener->onTouchBegan = [level3](Touch *t, Event *e){
		if (level3->getBoundingBox().containsPoint(t->getLocation()))
		{
			if (UserDefault::getInstance()->getBoolForKey("sound"))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
			}
			UserDefault::getInstance()->setIntegerForKey("level", 3);
			Director::getInstance()->pushScene(ChooseHero::createScene());
		}


		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(level3Listener, level3);


	auto level4 = Sprite::create("level4.png");
	addChild(level4);
	level4->setPosition(visibleSize.width / 2, visibleSize.height * 2 / 7);

	auto level4Listener = EventListenerTouchOneByOne::create();
	level4Listener->onTouchBegan = [level4](Touch *t, Event *e){
		if (level4->getBoundingBox().containsPoint(t->getLocation()))
		{
			if (UserDefault::getInstance()->getBoolForKey("sound"))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
			}
			UserDefault::getInstance()->setIntegerForKey("level", 4);
			Director::getInstance()->pushScene(ChooseHero::createScene());
		}


		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(level4Listener, level4);


	auto buttom = Sprite::create("buttom.png");
	addChild(buttom);
	buttom->setPosition(visibleSize.width / 2, level4->getPositionY() - level4->getContentSize().height);

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


void GameStartScene::menuCloseCallback(Ref* pSender)
{
	auto soundMenu = (MenuItemToggle*)pSender;
	
	if (soundMenu->getSelectedIndex() == 1) {
		
		UserDefault::getInstance()->setBoolForKey("sound", false);
		
	}
	else if (soundMenu->getSelectedIndex() == 0){
		
		UserDefault::getInstance()->setBoolForKey("sound", true);;
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
	}
}