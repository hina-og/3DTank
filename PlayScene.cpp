#include "PlayScene.h"
#include "Ground.h"
#include "Tank.h"
#include "Enemy.h"
#include "HUD.h"
#include "Engine/Image.h"
//#include "Engine/Camera.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

namespace 
{
	const int ENEMY_NUM{ 20 };
}

PlayScene::PlayScene(GameObject* parent)
	: GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Ground>(this);
	player = Instantiate<Tank>(this);
	enemyNum = ENEMY_NUM;
	for (int i = 0; i < enemyNum; i++) 
	{
		Instantiate<Enemy>(this);
	}
	Instantiate<HUD>(this);
}                                                                                                                                                                  
void PlayScene::Update()
{
	if (enemyNum <= 0)
	{
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}

