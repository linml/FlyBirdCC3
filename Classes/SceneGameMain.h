//
//  SceneGameMain.h
//  FlappyBird
//
//  Created by linminglu on 14-2-11.
//
//

#ifndef __FlappyBird__SceneGameMain__
#define __FlappyBird__SceneGameMain__

#include <iostream>
#include "cocos2d.h"

using namespace cocos2d;
using namespace std;

class SceneGameMain :public Layer
{
protected:
    bool init();
    
public:
    SceneGameMain();
    ~SceneGameMain();
   static  Scene *createscene();
    CREATE_FUNC(SceneGameMain);
    void   setPhyWorld(PhysicsWorld* world);
private:
    void createBirdBox();
    void createBianJie();
     bool onTouchBegan(Touch *touch, Event *unused_event);
     void onTouchMoved(Touch *touch, Event *unused_event);
     void onTouchEnded(Touch *touch, Event *unused_event);
     void onTouchCancelled(Touch *touch, Event *unused_event);
     void updateBird(float t);
    void createTopGanTi();
    void createBottomGanti();
    void createBackGround();
    
    bool  onContactBegin(EventCustom* event, const PhysicsContact& contact);
protected:
     void btnDebugDrawCallback(Object* pSender);
private:
    PhysicsWorld* m_world;
    Sprite *pBird;
    float _tanTiao;
    float _biaozhungaodu;
    float _totalGamdu;
    
};

#endif /* defined(__FlappyBird__SceneGameMain__) */
