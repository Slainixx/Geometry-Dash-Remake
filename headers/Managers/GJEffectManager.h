#include "includes.h"

// alk1m123's header used as a base. still unfinished

class GJEffectManager : public cocos2d::CCNode
{
	TriggerEffectDelegate* m_pTriggerEffectDelegate;
	cocos2d::CCDictionary* m_pColourActions;
	cocos2d::CCDictionary* m_pColourActionSprites;
	cocos2d::CCDictionary* m_pPulseEffectForGroupID;
	cocos2d::CCDictionary* m_pColourCache;
	cocos2d::CCDictionary* m_pOpacityActionForGroup;
	cocos2d::CCDictionary* m_pUnkDict6;
	cocos2d::CCArray* m_pOpacityActions;
	cocos2d::CCArray* m_pTouchActions;
	cocos2d::CCDictionary* m_pCountActions;
	cocos2d::CCArray* m_pDeathActions;
	cocos2d::CCArray* m_pCollisionActions;
	cocos2d::CCDictionary* m_pUnkDict16;
	cocos2d::CCDictionary* m_pUnkDict15;
	std::vector<InheritenceNode *> m_pInheritenceNodes;
	cocos2d::CCDictionary* m_pUnkDictCollosion3;
	cocos2d::CCDictionary* m_pUnkDictCollosion1;
	cocos2d::CCDictionary* m_pUnkDictCollosion2;
	std::vector<ColorAction*> m_pColourActions;
	std::vector<ColorActionSprites*> m_pColourActionSprite;
	bool m_bPulseExistsForGroup[1100];
	bool field_12D;
	bool field_5A1;
	bool m_bOpacityExistsForGroup[1100];
	int m_nItemValues[1100];
	DWORD field_68D;
	DWORD field_68E;
	cocos2d::CCArray* m_pUnkArray7;
	cocos2d::CCArray* m_pUnkArray8;
	cocos2d::CCDictionary* m_pUnkDict8;
	std::vector<bool> m_bGroupToggled;
	cocos2d::CCDictionary* m_pTriggeredIDs;
	cocos2d::CCDictionary* m_pFollowCommandObjects;
	cocos2d::CCArray* m_pSpawnCommandObjects;
	cocos2d::CCArray* m_pMoveCommandObjects;
	cocos2d::CCArray* m_pUnkArray6;
	cocos2d::CCNode* m_pUnkNode1;
	cocos2d::CCDictionary* m_pDeltaMoveActions;
	cocos2d::CCDictionary* m_pMoveCNodes2;
	cocos2d::CCDictionary* m_pFollowGroups;
	cocos2d::CCDictionary* m_pMoveCNodes;
	float m_fClkTimer;
	float m_fXVelocity;
	float m_fYVelocity;
	bool m_bEnableMoveOptimisation;
};
