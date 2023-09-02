#include "../headers/includes.h"
#include <event.xsd>

class ButtonSprite : public cocos2d::Sprite
{
public:
    bool init(const std::string& normalImage, const std::string& selectedImage, const std::function<void()>& callback);

    static ButtonSprite* create(const std::string& normalImage, const std::string& selectedImage, const std::function<void()>& callback);

    void onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

private:
    std::function<void()> clickCallback;
};

bool ButtonSprite::init(const std::string& normalImage, const std::string& selectedImage, const std::function<void()>& callback)
{
    if (!Sprite::initWithFile(normalImage))
    {
        return false;
    }

    // Store the callback function
    clickCallback = callback;

    // Create a touch listener
    auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);

    touchListener->onTouchBegan = [this](cocos2d::Touch* touch, cocos2d::Event* event) {
        if (this->getBoundingBox().containsPoint(touch->getLocation()))
        {
            this->setTexture(selectedImage);
            return true;
        }
        return false;
        };

    touchListener->onTouchEnded = [this](cocos2d::Touch* touch, cocos2d::Event* event) {
        this->setTexture(normalImage);
        if (this->getBoundingBox().containsPoint(touch->getLocation()))
        {
            if (clickCallback)
            {
                clickCallback();
            }
        }
        };

    cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

ButtonSprite* ButtonSprite::create(const std::string& normalImage, const std::string& selectedImage, const std::function<void()>& callback)
{
    auto button = new ButtonSprite();
    if (button && button->init(normalImage, selectedImage, callback))
    {
        button->autorelease();
        return button;
    }
    CC_SAFE_DELETE(button);
    return nullptr;
}

void ButtonSprite::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
}

int main()
{
    // Create a scene
    auto scene = cocos2d::Scene::create();

    // Create a button
    auto button = ButtonSprite::create("normal_button.png", "selected_button.png", []() {
        // Button click callback
        CCLOG("Button clicked!");
        });

    // Set the button's position
    button->setPosition(cocos2d::Vec2(100, 100));

    // Add the button to the scene
    scene->addChild(button);

    // Run the scene
    cocos2d::Director::getInstance()->runWithScene(scene);

    return 0;
}
