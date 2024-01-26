#pragma once
#include "Engine/GameObject.h"

class Ground :
	public GameObject
{
	int hModel_;
public:
	Ground(GameObject* parent);
	~Ground();
	void Initialize();
	void Update();
	void Draw();
	void Release();
	int GetModelHandle() { return (hModel_); }
};

