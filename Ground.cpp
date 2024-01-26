#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/GameObject.h"

Ground::Ground(GameObject* parent)
	: GameObject(parent, "Ground"), hModel_(-1)
{
}

Ground::~Ground()
{
}

void Ground::Initialize()
{
	hModel_ = Model::Load("Model\\ground.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,-5 };
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Ground::Release()
{
}
