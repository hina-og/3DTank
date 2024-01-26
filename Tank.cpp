#include "Tank.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/Debug.h"
#include "Ground.h"
#include "TankHead.h"
#include "Engine/Camera.h"


enum CAM_TYPE
{
	FIXED_TYPE,     //�Œ�
	TPS_NOROT_TYPE, //�R�l�̉�]�Ȃ�
	TPS_TYPE,       //�R�l��
	FPS_TYPE,       //�P�l��
	MAX_TYPE        //�ԕ�(�`�F�b�N�p�̒l)
};

Tank::Tank(GameObject* parent)
	: GameObject(parent, "Tank"), hModel_(-1),speed_(0.1),front_({0,0,1,0}),camState_(CAM_TYPE::FIXED_TYPE)
{
}

void Tank::Initialize()
{
	Instantiate<TankHead>(this);
	hModel_ = Model::Load("Model\\tankbody.fbx");
	assert(hModel_ >= 0);
}

void Tank::Update()
{
	XMMATRIX rotY = XMMatrixIdentity();
	XMVECTOR move{ 0,0,0,0 };
	XMVECTOR rotVec{ 0,0,0,0 };
	float dir = 0;
	if (Input::IsKey(DIK_W))
	{
		/*rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
		rotVec = XMVector3TransformCoord(front_, rotY);

		move = speed_ * rotVec;
		XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
		pos = pos + move;
		XMStoreFloat3(&(transform_.position_), pos);*/

		dir = 1.0;
	}
	if (Input::IsKey(DIK_S))
	{
		
		dir = -1.0;
	}
	if (Input::IsKey(DIK_A))
	{
		transform_.rotate_.y -= 1.5f;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.rotate_.y += 1.5f;
	}

	rotY = XMMatrixRotationY(XMConvertToRadians(transform_.rotate_.y));
	rotVec = XMVector3TransformCoord(front_, rotY);

	move = speed_ * rotVec;
	XMVECTOR pos = XMLoadFloat3(&(transform_.position_));
	//pos = pos - move;
	pos = pos + dir * move;
	XMStoreFloat3(&(transform_.position_), pos);

	/*Debug::Log("rot=");
	Debug::Log(transform_.rotate_.y, true);*/
	Ground* pGround = (Ground*)FindObject("Ground");
	int hGmodel = pGround->GetModelHandle();

	RayCastData data;
	data.start = transform_.position_;
	data.start.y = 0;
	data.dir = XMFLOAT3({ 0,-1,0 });
	Model::RayCast(hGmodel, &data);

	if (data.hit == true)
	{
		transform_.position_.y = -data.dist + 0.5f;
	}

	if (Input::IsKeyDown(DIK_Z))
	{
		camState_ += 1;
		if (camState_ == CAM_TYPE::MAX_TYPE)
			camState_ = CAM_TYPE::FIXED_TYPE;
	}

	switch (camState_)
	{
		case CAM_TYPE::FIXED_TYPE:
		{
			Camera::SetPosition(XMFLOAT3(0, 20, -20));
			Camera::SetTarget(XMFLOAT3(0,0,0));
			break;
		}
		case CAM_TYPE::TPS_NOROT_TYPE:
		{
			XMFLOAT3 camPos = transform_.position_;
			camPos.y = transform_.position_.y + 15.0f;
			camPos.z = transform_.position_.z - 10.0f;
			Camera::SetPosition(camPos);
			Camera::SetTarget(transform_.position_);
			break;
		}
		case CAM_TYPE::TPS_TYPE:
		{
			Camera::SetTarget(transform_.position_);
			XMVECTOR vEye{ 0,5,-10,0 };
			vEye = XMVector3TransformCoord(vEye, rotY);
			XMFLOAT3 camPos;
			XMStoreFloat3(&camPos, pos + vEye);
			Camera::SetPosition(camPos);
			break;
		}
		case CAM_TYPE::FPS_TYPE:
		{
			Camera::SetPosition(transform_.position_);
			XMFLOAT3 camTarget;
			XMStoreFloat3(&camTarget, pos + move);
			/*XMStoreFloat3(&camTarget, pos * move);*/
			Camera::SetTarget(camTarget);
			break;
		}
		default:
		{
			break;
		}
	}
}

void Tank::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Tank::Release()
{
}