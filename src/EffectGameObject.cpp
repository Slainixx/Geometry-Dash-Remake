#include "cocos2d.h"

class EffectGameObject : public cocos2d::Node
{
public:
    bool init(float duration, const std::function<void()>& callback);

    static EffectGameObject* create(float duration, const std::function<void()>& callback);

    void play();

private:
    float effectDuration;
    std::function<void()> completionCallback;
};

bool EffectGameObject::init(float duration, const std::function<void()>& callback)
{
    if (!Node::init())
    {
        return false;
    }

    // Store the effect duration and completion callback function
    effectDuration = duration;
    completionCallback = callback;

    // Create and schedule a delayed callback to trigger the completion
    auto delay = cocos2d::DelayTime::create(effectDuration);
    auto callFunc = cocos2d::CallFunc::create([this]() {
        if (completionCallback)
        {
            completionCallback();
        }
        this->removeFromParent();
        });

    this->runAction(cocos2d::Sequence::create(delay, callFunc, nullptr));

    return true;
}

EffectGameObject* EffectGameObject::create(float duration, const std::function<void()>& callback)
{
    auto effect = new EffectGameObject();
    if (effect && effect->init(duration, callback))
    {
        effect->autorelease();
        return effect;
    }
    CC_SAFE_DELETE(effect);
    return nullptr;
}

void EffectGameObject::play()
{
    // Start playing the effect
    this->setVisible(true);
    // Implement the effect's animation or action here
}

int main()
{
    // Create a scene
    auto scene = cocos2d::Scene::create();

    // Create an effect game object
    auto effect = EffectGameObject::create(2.0f, []() {
        // Completion callback
        CCLOG("Effect completed!");
        });

    // Add the effect to the scene
    scene->addChild(effect);

    // Play the effect
    effect->play();

    // Run the scene
    cocos2d::Director::getInstance()->runWithScene(scene);

    return 0;
}
