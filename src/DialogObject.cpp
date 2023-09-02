#include "cocos2d.h"

class DialogObject : public cocos2d::Node
{
public:
    bool init(const std::string& message, const std::function<void()>& callback);

    static DialogObject* create(const std::string& message, const std::function<void()>& callback);

    void show();
    void hide();

private:
    std::function<void()> closeCallback;
};

bool DialogObject::init(const std::string& message, const std::function<void()>& callback)
{
    if (!Node::init())
    {
        return false;
    }

    // Store the close callback function
    closeCallback = callback;

    // Create a dialog background sprite
    auto background = cocos2d::Sprite::create("dialog_bg.png");
    background->setPosition(cocos2d::Director::getInstance()->getVisibleSize() / 2);
    this->addChild(background);

    // Create a label to display the message
    auto label = cocos2d::Label::createWithTTF(message, "fonts/arial.ttf", 24);
    label->setPosition(background->getContentSize() / 2);
    background->addChild(label);

    // Create a close button
    auto closeButton = cocos2d::MenuItemImage::create(
        "close_button_normal.png",
        "close_button_selected.png",
        CC_CALLBACK_1(DialogObject::hide, this));
    closeButton->setPosition(background->getContentSize().width - 20, background->getContentSize().height - 20);

    // Create a menu with the close button
    auto menu = cocos2d::Menu::create(closeButton, nullptr);
    menu->setPosition(cocos2d::Vec2::ZERO);
    background->addChild(menu);

    // Hide the dialog initially
    this->setVisible(false);

    return true;
}

DialogObject* DialogObject::create(const std::string& message, const std::function<void()>& callback)
{
    auto dialog = new DialogObject();
    if (dialog && dialog->init(message, callback))
    {
        dialog->autorelease();
        return dialog;
    }
    CC_SAFE_DELETE(dialog);
    return nullptr;
}

void DialogObject::show()
{
    this->setVisible(true);
}

void DialogObject::hide()
{
}

void DialogObject::hide(cocos2d::Ref* sender)
{
    this->setVisible(false);
    if (closeCallback)
    {
        closeCallback();
    }
}

int main()
{
    // Create a scene
    auto scene = cocos2d::Scene::create();

    // Create a dialog object
    auto dialog = DialogObject::create("Hello, this is a dialog!", []() {
        // Close button callback
        CCLOG("Dialog closed!");
        });

    // Add the dialog to the scene
    scene->addChild(dialog);

    // Show the dialog
    dialog->show();

    // Run the scene
    cocos2d::Director::getInstance()->runWithScene(scene);

    return 0;
}
