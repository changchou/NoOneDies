#include "GameOverScene.h"

Scene* GameOver::createScene(){
	auto s = Scene::create();
	auto l = GameOver::create();
	s->addChild(l);
	return s;
}

bool GameOver::init(){

	LayerColor::initWithColor(Color4B::WHITE);

	visibleSize = Director::getInstance()->getVisibleSize();

	auto label1 = Label::create();
	label1->setColor(Color3B::BLACK);
	label1->setSystemFontSize(40);
	addChild(label1);
	label1->setPosition(visibleSize.width / 2, visibleSize.height * 3 / 4);

	switch (UserDefault::getInstance()->getIntegerForKey("level"))
	{
	case 1:
		label1->setString("NORMAL");
		break;
	case 2:
		label1->setString("NIGHTMARE");
		break;
	case 3:
		label1->setString("HELL");
		break;
	case 4:
		label1->setString("INFERNO");
		break;
	}

	auto ground1 = Sprite::create();
	ground1->setColor(Color3B(0, 0, 0));
	ground1->setTextureRect(Rect(0, 0, visibleSize.width / 2, 3));
	ground1->setPosition(visibleSize.width / 2, label1->getPositionY() - label1->getContentSize().height / 2);
	addChild(ground1);

	auto label2 = LabelTTF::create(UserDefault::getInstance()->getStringForKey("time") + "\"", "Arial-BoldMT", 36);
	label2->setFontFillColor(Color3B::BLACK);
	label2->setPosition(visibleSize / 2);
	addChild(label2);

	auto label3 = LabelTTF::create("BACK", "Arial-BoldMT", 30);
	label3->setFontFillColor(Color3B::BLACK);
	label3->setPosition(visibleSize.width / 3, visibleSize.height / 4);
	addChild(label3);

	auto label4 = LabelTTF::create("RETRY", "Arial-BoldMT", 30);
	label4->setFontFillColor(Color3B::BLACK);
	label4->setPosition(visibleSize.width * 2 / 3, visibleSize.height / 4);
	addChild(label4);

	auto ground2 = Sprite::create();
	ground2->setColor(Color3B(0, 0, 0));
	ground2->setTextureRect(Rect(0, 0, visibleSize.width / 2, 3));
	ground2->setPosition(visibleSize.width / 2, label3->getPositionY() + label3->getContentSize().height / 2);
	addChild(ground2);

	auto backListener = EventListenerTouchOneByOne::create();
	backListener->onTouchBegan = [label3](Touch *t, Event *e){

		if (label3->getBoundingBox().containsPoint(t->getLocation())){

			if (UserDefault::getInstance()->getBoolForKey("sound"))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
			}
			Director::getInstance()->popToRootScene();
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(backListener, label3);


	auto retryListener = EventListenerTouchOneByOne::create();
	retryListener->onTouchBegan = [label4](Touch *t, Event *e){

		if (label4->getBoundingBox().containsPoint(t->getLocation())){

			if (UserDefault::getInstance()->getBoolForKey("sound"))
			{
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("click.mp3");
			}
			Director::getInstance()->pushScene(HelloWorld::createScene());
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(retryListener, label4);

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