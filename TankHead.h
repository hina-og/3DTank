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
    /// ƒ‚ƒfƒ‹”Ô†‚ğ•Ô‚·ŠÖ”
    /// </summary>
    /// <returns>ƒ‚ƒfƒ‹”Ô†</returns>
    int GetModelHandle() { return hModel_ ; }
};

