#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player.h"),hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0,0,-5 };
}

void Player::Update()
{
	
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
