//
//  SceneGameMain.cpp
//  FlappyBird
//
//  Created by linminglu on 14-2-11.
//
//

#include "SceneGameMain.h"
#include "CManagerAudio.h"

Scene *SceneGameMain::createscene()
{
    auto pScene = Scene::createWithPhysics();
    pScene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);;
    auto pLayer=SceneGameMain::create();
    pLayer->setPhyWorld(pScene->getPhysicsWorld());
    pScene->getPhysicsWorld()->setGravity(Vect(0,-1000));
    pScene->addChild(pLayer);

    return pScene;
}

void SceneGameMain::setPhyWorld(cocos2d::PhysicsWorld *world)
{
    m_world=world;
}

void SceneGameMain::createBianJie() //边界
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width/2,visibleSize.height/2));
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);
}

void SceneGameMain::createBirdBox() //鸟
{
     Size visibleSize = Director::getInstance()->getWinSize();
    pBird = Sprite::create("bird.png");
    pBird->setTag(0);
	auto body = PhysicsBody::createBox(Size(80, 60));
    pBird->setPhysicsBody(body);
    body->setRotationEnable(false);
    body->setDynamic(true);
    pBird->setPosition(Point(visibleSize.width*0.5,visibleSize.height*0.5));
    this->addChild(pBird,1,7);

}

void SceneGameMain::createTopGanTi() //顶部数据
{
    
    
   // auto pSprite=Sprite::createWithTexture(pTexture);
    auto s=Director::getInstance()->getWinSize();
    RenderTexture *pKRender= RenderTexture::create(202, 260);
    pKRender->setPosition(Point(s.width/2, s.height/2));
 //   pKRender->begin();
    pKRender->beginWithClear(255, 255, 255, 255);
    auto pSprite=Sprite::createWithSpriteFrameName("pipetop.png");
    pSprite->cocos2d::Node::setPosition(Point::ZERO);
    pSprite->setAnchorPoint(Point::ZERO);
    pSprite->visit();
    pSprite=Sprite::createWithSpriteFrameName("middle.png");
    pSprite->cocos2d::Node::setPosition(Point(2,64));
    pSprite->setAnchorPoint(Point::ZERO);
    pSprite->visit();
    
    
    
    
    pKRender->end();
   // addChild(pKRender);
    
    
    
    auto pTop=Sprite::createWithTexture(pKRender->getSprite()->getTexture());
    pTop->setPosition(Point(s.width/2, s.height/2+300));
    addChild(pTop);
    auto body = PhysicsBody::createBox(pKRender->getSprite()->getTexture()->getContentSize());
    pTop->setPhysicsBody(body);
    pTop->getPhysicsBody()->setDynamic(false);
}


void SceneGameMain::createBackGround()
{
    auto s=Director::getInstance()->getWinSize();
    auto pLayer=LayerColor::create(Color4B(255, 255,0, 255), s.width, s.height);
    addChild(pLayer);
}


void SceneGameMain::createBottomGanti()
{
    
}

void SceneGameMain::updateBird(float t)
{
    if (pBird->getPhysicsBody()->getVelocity().y>_tanTiao) {
        pBird->getPhysicsBody()->setVelocity(Point(pBird->getPhysicsBody()->getVelocity().x,_tanTiao));
    }
    float rotation =  (pBird->getPhysicsBody()->getVelocity().y)/1000 *90.0;
    pBird->setRotation(rotation);
}


bool SceneGameMain::onTouchBegan(Touch *touch, Event *unused_event)
{
   pBird->getPhysicsBody()->setVelocity(Point(pBird->getPhysicsBody()->getVelocity().x,_tanTiao));
   
    CManagerAudio::getInstance()->playJump();
    return true;
}
void SceneGameMain::onTouchMoved(Touch *touch, Event *unused_event)
{
    
}
void SceneGameMain::onTouchEnded(Touch *touch, Event *unused_event)
{
    
}
void SceneGameMain::onTouchCancelled(Touch *touch, Event *unused_event)
{
    
}
bool SceneGameMain::init()
{
    SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("pipebottom.png", Rect(0, 0, 64, 64)), "pipebottom.png");
    SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("middle.png", Rect(0, 0, 60, 23)), "middle.png");
    SpriteFrameCache::getInstance()->addSpriteFrame(SpriteFrame::create("pipetop.png", Rect(0, 0, 64, 64)), "pipetop.png");
    createBackGround();
    createBianJie();
    createBirdBox();
   // m_world->setGravity(Vect(0,-10));
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(SceneGameMain::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(SceneGameMain::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(SceneGameMain::onTouchEnded, this);
    touchListener->onTouchCancelled = CC_CALLBACK_2(SceneGameMain::onTouchCancelled, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    _touchListener = touchListener;
    schedule(schedule_selector(SceneGameMain::updateBird));
    createTopGanTi();
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_2(SceneGameMain::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    

    

    return true;
}


bool  SceneGameMain::onContactBegin(EventCustom* event, const PhysicsContact& contact)
{
    auto node = contact.getShapeA()->getBody()->getNode();// .node;
    if (node->getTag()==7)
    {
        log("is bird tag");
        CManagerAudio::getInstance()->playBeginContact();
        _eventDispatcher->removeEventListener(_touchListener);
        _touchListener = nullptr;
    }
    
    return true;
    
    
}

SceneGameMain::~SceneGameMain()
{
    _eventDispatcher->removeEventListener(_touchListener);
    _touchListener=nullptr;
}

SceneGameMain::SceneGameMain()
{
    _tanTiao=600;
     _biaozhungaodu=800;
    _totalGamdu=Director::getInstance()->getWinSize().height;
}




void SceneGameMain::btnDebugDrawCallback(Object* pSender)
{
    
    if(m_world->getDebugDrawMask() != PhysicsWorld::DEBUGDRAW_NONE) {
        m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_NONE);
    }
    else {
        m_world->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    }
}
