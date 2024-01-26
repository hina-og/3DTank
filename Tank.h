#pragma once
#include "Engine/GameObject.h"
#include "Ground.h"
#include "Engine/Text.h"
class Tank :
    public GameObject
{
    XMVECTOR front_;
    double speed_;
    int hModel_;
    int camState_;
public:
    Tank(GameObject* parent);
    void Initialize();
    void Update();
    void Draw();
    void Release();
};

