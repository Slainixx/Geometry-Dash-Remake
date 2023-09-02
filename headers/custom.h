#include "includes.h"

class RobTop
{
public:
    static cocos2d::CCArray *splitToCCArray(std::string _string, char *_splitter);
};

namespace Globals
{
    const std::string XORMessage = "14251";
    const std::string XORLevelPass = "26364";
    const std::string XORAccountPassword = "37526";
    int ShardTypes[5] = {1, 2, 3, 4, 5};

    cocos2d::CCPoint *gScollLayerPos = { 0.0f , 0.0f };
    cocos2d::ccColor3B gNormalBarCol = { 0x00, 0xFF, 0x00 };
    cocos2d::ccColor3B gPracticeBarCol = { 0x00, 0xFF, 0xFF };
    bool gClickedPlay = false;
}