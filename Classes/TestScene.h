#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class TestScene : public cocos2d::Scene
{
public:
    CREATE_FUNC(TestScene)
    
private:
    cocos2d::Sprite* icon { nullptr };
    std::function<void()> action { nullptr };
    
private:
    TestScene();
    ~TestScene();
    bool init() override;

    void setupIcon();
    void setupResetButton();
    void reset();

public:
    void onEnterTransitionDidFinish() override;
    
private:
    void move();
    void rotate();
    void scale();
    void skew();
    void resize();
    void jump();
    void bezier();
    void blink();
    void fade();
    void tint();
    void delay();
    void action_float();
    void animate();
    
    void reverse_time();
    void targeted_action();
    void repeat();
    void repeat_forever();
    void sequence();
    void spawn();
    
    void show();
    void hide();
    void toggle_visibility();
    void remove_self();
    void flip_x();
    void flip_y();
    void place();
    void callfunc();
    void callfunc_n();
    
    void speed();
    void follow();
};

#endif // __HELLOWORLD_SCENE_H__
