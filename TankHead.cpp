#include "TankHead.h"
#include "Bullet.h"
#include "Engine/Model.h"
#include "Engine/Input.h"

TankHead::TankHead(GameObject* parent)
	:GameObject(parent,"TankHead"),hModel_(-1)
{
}

TankHead::~TankHead()
{
}

void TankHead::Initialize()
{
	hModel_ = Model::Load("Model\\tankhead.fbx");
	assert(hModel_ >= 0);
}

void TankHead::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.rotate_.y -= 2.5f;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.rotate_.y += 2.5f;
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		XMFLOAT3 cannonTopPos = Model::GetBonePosition(hModel_, "CannonPos");
		XMFLOAT3 cannonRootPos = Model::GetBonePosition(hModel_, "CannonRoot");

		XMVECTOR vtop = XMLoadFloat3(&cannonTopPos);
		XMVECTOR vroot = XMLoadFloat3(&cannonRootPos);
		XMVECTOR moveDir = vtop - vroot;
		moveDir = XMVector3Normalize(moveDir);
		XMFLOAT3 vmove;
		XMStoreFloat3(&vmove, moveDir);

		Bullet* pBullet = Instantiate<Bullet>(this->GetParent()->GetParent());
		pBullet->SetPosition(cannonTopPos);
		pBullet->SetMoveDir(vmove);
		pBullet->SetSpeed(0.5);
	}
}

void TankHead::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TankHead::Release()
{
}
