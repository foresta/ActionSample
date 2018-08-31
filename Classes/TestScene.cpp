#include "TestScene.h"

USING_NS_CC;

TestScene::TestScene() {}
TestScene::~TestScene() {}

bool TestScene::init()
{
    if (!Scene::init()) return false;
 
    this->setupIcon();
    this->setupResetButton();
    
    this->action = [this](){ this->move(); };
    
    return true;
}

void TestScene::setupIcon()
{
    Size winSize { Director::getInstance()->getWinSize() };
    // アイコン
    Sprite* icon { Sprite::create("HelloWorld.png") };
    icon->setPosition(Vec2(winSize.width * 0.5f, winSize.height * 0.5f));
    this->addChild(icon);
    this->icon = icon;
}

void TestScene::setupResetButton()
{
    Size winSize { Director::getInstance()->getWinSize() };
    Vec2 origin { Director::getInstance()->getVisibleOrigin() };
    
    // メニュー
    MenuItemImage* closeItem { MenuItemImage::create("CloseNormal.png", "CloseSelected.png", [this](Ref* _){
        this->reset();
    }) };
    closeItem->setScale(3.f);
    closeItem->setPosition({ winSize.width -100, winSize.height - 100});
    
    
    Menu* menu { Menu::create(closeItem, nullptr) };
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
}

void TestScene::reset()
{
    if (this->icon)
    {
        this->icon->removeFromParent();
        this->icon = nullptr;
    }
    
    this->setupIcon();
    this->action();
}

void TestScene::onEnterTransitionDidFinish()
{
    Scene::onEnterTransitionDidFinish();

    this->action();
}

#pragma mark -
#pragma mark private

void TestScene::move()
{
    this->icon->runAction(MoveBy::create(3.f, Vec2(50.f, 0)));
}

void TestScene::rotate()
{
    
}

void TestScene::scale()
{
    
}

void TestScene::skew()
{
    
}

void TestScene::resize()
{
    
}

void TestScene::jump()
{
    
}

void TestScene::bezier()
{
    
}

void TestScene::blink()
{
    
}

void TestScene::fade()
{
    
}

void TestScene::tint()
{
    
}

void TestScene::delay()
{
    
}

void TestScene::action_float()
{
    
}

void TestScene::animate()
{
    
}

void TestScene::reverse_time()
{
    
}

void TestScene::targeted_action()
{
    
}

void TestScene::repeat()
{
    
}

void TestScene::repeat_forever()
{
    
}

void TestScene::sequence()
{
    
}

void TestScene::spawn()
{
    
}


void TestScene::show()
{
    
}

void TestScene::hide()
{
    
}

void TestScene::toggle_visibility()
{
    
}

void TestScene::remove_self()
{
    
}

void TestScene::flip_x()
{
    
}

void TestScene::flip_y()
{
    
}

void TestScene::place()
{
}

void TestScene::callfunc()
{
    
}

void TestScene::callfunc_n()
{
    
}

void TestScene::speed()
{
    
}


void TestScene::follow()
{
    
}
