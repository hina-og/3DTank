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
    /// ���f���ԍ���Ԃ��֐�
    /// </summary>
    /// <returns>���f���ԍ�</returns>
    int GetModelHandle() { return hModel_ ; }
};

