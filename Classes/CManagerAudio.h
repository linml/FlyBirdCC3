//
//  CManagerAudio.h
//  FlappyBird
//
//  Created by linminglu on 14-2-17.
//
//

#ifndef __FlappyBird__CManagerAudio__
#define __FlappyBird__CManagerAudio__

#include <iostream>
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;
class CManagerAudio
{
public:
    void playBeginContact();
    void playJump();
    
    static  CManagerAudio *getInstance();
private:
    CManagerAudio();
    ~CManagerAudio();
    static CManagerAudio *gCmanager;
};



#endif /* defined(__FlappyBird__CManagerAudio__) */
