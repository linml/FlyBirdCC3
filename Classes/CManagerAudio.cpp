//
//  CManagerAudio.cpp
//  FlappyBird
//
//  Created by linminglu on 14-2-17.
//
//

#include "CManagerAudio.h"
CManagerAudio *CManagerAudio::gCmanager=NULL;
CManagerAudio::CManagerAudio()
{
    
}
CManagerAudio *CManagerAudio::getInstance()
{
    if (gCmanager==NULL) {
        gCmanager=new CManagerAudio();
    }
    return gCmanager;
}


CManagerAudio::~CManagerAudio()
{
    
}

void CManagerAudio::playBeginContact()
{
    SimpleAudioEngine::getInstance()->playEffect("sfx_hit.wav");
    
}

void CManagerAudio::playJump()
{
      SimpleAudioEngine::getInstance()->playEffect("sfx_swooshing.wav");
}