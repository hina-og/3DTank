#pragma once
#include "Engine/GameObject.h"
class TankHead :
    public GameObject
{
    int hModel_;
public:
    TankHead(GameObject* parent);
    ~TankHead();
    void Initialize();
    void Update();
    void Draw();
    void Release();
    /// <summary>
    /// モデル番号を返す関数
    /// </summary>
    /// <returns>モデル番号</returns>
    int GetModelHandle() { return hModel_ ; }
};

