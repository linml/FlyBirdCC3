//
//  SceneNewGame.h
//  FlappyBird
//
//  Created by linminglu on 14-2-11.
//
//

#ifndef __FlappyBird__SceneNewGame__
#define __FlappyBird__SceneNewGame__

#include <iostream>
#include "cocos2d.h"
using namespace std;
using namespace cocos2d;
class SceneNewGame :public Layer
{
    
protected:
    bool init();
    void goToGameScene(cocos2d::Object *pSend);
public:
    static Scene *createScene();
    CREATE_FUNC(SceneNewGame)
    
};

#endif /* defined(__FlappyBird__SceneNewGame__) */
