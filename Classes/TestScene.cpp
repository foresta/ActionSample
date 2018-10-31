#include "TestScene.h"

USING_NS_CC;

TestScene::TestScene() {}
TestScene::~TestScene() {}

bool TestScene::init()
{
    if (!Scene::init()) return false;
 
    this->setupIcon();
    this->setupResetButton();
    
    this->action = CC_CALLBACK_0(TestScene::tint, this);
    
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
    MenuItemImage* resetButton { MenuItemImage::create("CloseNormal.png", "CloseSelected.png", [this](Ref* _){
        this->reset();
    }) };
    resetButton->setScale(3.f);
    resetButton->setPosition({ winSize.width -100, winSize.height - 100});
    
    
    Menu* menu { Menu::create(resetButton, nullptr) };
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
    
    this->resetButton = resetButton;
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

    this->runAction(Sequence::createWithTwoActions(DelayTime::create(2.f), CallFunc::create([this](){
        this->action();
    })));
}

#pragma mark -
#pragma mark private

#pragma mark Besic

void TestScene::move()
{
    this->icon->runAction(MoveBy::create(1.f, Vec2(50.f, 0)));
}

void TestScene::rotate()
{
    this->icon->runAction(RotateBy::create(1.f, 360.f));
}

void TestScene::scale()
{
    this->icon->runAction(ScaleBy::create(1.f, 2.f));
}

void TestScene::skew()
{
    this->icon->runAction(SkewBy::create(1.f, 30.f,0.f));
}

void TestScene::resize()
{
    this->icon->runAction(ResizeBy::create(1.f, Size(100,50)));
}

void TestScene::jump()
{
    float jumpHeight { 30.f };
    int count { 5 };
    this->icon->runAction(JumpBy::create(1.f, Vec2::ZERO, jumpHeight, count));
}

void TestScene::bezier()
{
    ccBezierConfig config {};
    config.endPosition = Vec2(50,0);
    config.controlPoint_1 = Vec2::ZERO;
    config.controlPoint_2 = Vec2(25,50);
    
    this->icon->runAction(BezierBy::create(1.f, config));
}

void TestScene::blink()
{
    this->icon->runAction(Blink::create(2.f, 5));
}

void TestScene::fade()
{
    this->icon->setOpacity(0.f);
    this->icon->runAction(FadeTo::create(2.f, 255));
}

void TestScene::tint()
{
    this->icon->runAction(TintTo::create(1.f, Color3B::RED));
}

#pragma mark -



void TestScene::action_float()
{
    
}

void TestScene::animate()
{
    
}

void TestScene::sequence()
{
    this->icon->runAction(
        Sequence::create(
            MoveBy::create(.5f, Vec2(50, 0)),
            MoveBy::create(1.f, Vec2(-100, 0)),
            MoveBy::create(.5f, Vec2(50, 0)),
            nullptr));
}

void TestScene::spawn()
{
    this->icon->runAction(
        Spawn::create(
            MoveBy::create(1.f, Vec2(50,0)),
            ScaleBy::create(1.f, 1.5f),
            RotateBy::create(1.f, 360),
            nullptr)
    );
}

void TestScene::delay()
{
    this->icon->runAction(Sequence::createWithTwoActions(DelayTime::create(3.f), MoveBy::create(1.f, Vec2(50, 0))));
}

void TestScene::reverse_time()
{
    MoveBy* move { MoveBy::create(1.f, Vec2(50,0)) };
    ReverseTime* reverse { ReverseTime::create(move->clone()) };
    this->icon->runAction(Sequence::createWithTwoActions(move, reverse));
}

void TestScene::targeted_action()
{
    // アイコンを動かしたのちに、閉じるボタンを拡大
    // 違うノードに対して一連の流れでアクションさせたい時に便利
    TargetedAction* iconMove { TargetedAction::create(this->icon, MoveBy::create(1.f, Vec2(50, 0))) };
    TargetedAction* resetButtonScale { TargetedAction::create() };
    
    this->runAction(
                    Sequence::createWithTwoActions(
                    );
        );
}

void TestScene::repeat()
{
    
}

void TestScene::repeat_forever()
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
