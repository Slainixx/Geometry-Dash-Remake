#include "cocos2d.h"

class DropdownLayer : public cocos2d::Layer
{
public:
    DropdownLayer();
    virtual bool init();
    CREATE_FUNC(DropdownLayer);

    void toggleDropdown();

private:
    bool isOpen;
    cocos2d::Menu* dropdownMenu;
};

DropdownLayer::DropdownLayer()
    : isOpen(false), dropdownMenu(nullptr)
{
}

bool DropdownLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }

    // Create the dropdown button
    auto dropdownButton = cocos2d::MenuItemImage::create(
        "dropdown_button_normal.png",
        "dropdown_button_selected.png",
        CC_CALLBACK_0(DropdownLayer::toggleDropdown, this)
    );

    dropdownButton->setPosition(100, 100);

    // Create the dropdown menu with options (simplified)
    auto option1 = cocos2d::MenuItemLabel::create(
        cocos2d::Label::createWithTTF("Option 1", "fonts/arial.ttf", 24)
    );

    auto option2 = cocos2d::MenuItemLabel::create(
        cocos2d::Label::createWithTTF("Option 2", "fonts/arial.ttf", 24)
    );

    dropdownMenu = cocos2d::Menu::create(option1, option2, nullptr);
    dropdownMenu->setVisible(false);

    option1->setCallback([]() {
        // Handle Option 1 selection
        CCLOG("Option 1 selected!");
        });

    option2->setCallback([]() {
        // Handle Option 2 selection
        CCLOG("Option 2 selected!");
        });

    option1->setPosition(100, 60);
    option2->setPosition(100, 20);

    this->addChild(dropdownButton);
    this->addChild(dropdownMenu);

    return true;
}

DropdownLayer::CREATE_FUNC(DropdownLayer)
{
}

void DropdownLayer::toggleDropdown()
{
    isOpen = !isOpen;
    dropdownMenu->setVisible(isOpen);
}

int main(int argc, char** argv)
{
    // Initialize the application
    cocos2d::Application app(argc, argv);

    // Create the dropdown scene
    auto scene = cocos2d::Scene::create();
    auto dropdownLayer = DropdownLayer::create();
    scene->addChild(dropdownLayer);

    // Run the scene
    return app.run(scene);
}
