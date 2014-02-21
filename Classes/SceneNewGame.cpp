//
//  SceneNewGame.cpp
//  FlappyBird
//
//  Created by linminglu on 14-2-11.
//
//

#include "SceneNewGame.h"
#include "SceneGameMain.h"
Scene *SceneNewGame::createScene()
{
    auto pScene= Scene::create();
    auto pLayer=SceneNewGame::create();
    pScene->addChild(pLayer);
	cout<<"aaaaaaaaaaaaaa"<<endl;
    return pScene;
}

bool SceneNewGame::init()
{
    
    auto size=Director::getInstance()->getWinSize();
    auto pColorLayer=LayerColor::create(Color4B((int)255*0.61, (int)255*0.74, (int)255*0.86, 255), size.width, size.height);
    addChild(pColorLayer);
    MenuItemFont::setFontSize(150);
    MenuItemFont * pNewGame=MenuItemFont::create("New Game", CC_CALLBACK_1(SceneNewGame::goToGameScene, this));
    pNewGame->setColor(Color3B(255, 0, 0));
    auto pMenu=Menu::create(pNewGame, NULL);
    addChild(pMenu);
    pMenu->setPosition(Point(size.width *0.5, size.height*0.5));
    
    return true;
    
}

void SceneNewGame::goToGameScene(cocos2d::Object *pSend)
{
    auto pScene=SceneGameMain::createscene();
    Director::getInstance()->replaceScene(pScene);
}
