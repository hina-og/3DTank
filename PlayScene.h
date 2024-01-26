#pragma once
#include "Engine/GameObject.h"
//#include "Tank.h"

class Tank;

class PlayScene :
    public GameObject
{
    Tank* player;
    int enemyNum;
public:
    PlayScene(GameObject* parent);
    void Initialize();
    void Update();
    void Draw();
    void Release();
    void DethEnemy() { enemyNum--; }
    int GetEnemyNumg() { return enemyNum; }
};

