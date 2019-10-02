#include "DXUT.h"
#include "Marine.h"

Marine::Marine()
{
	Create(L"Units/P/Marine/Idle/i1.png");

	_Hp = 10;
	_FullHp = 10;
	_Speed = 8;
	_range = 500;
	_v = { 1,1 };
	_objtype = T_obj_type::t_marine;
	_teamtype = T_team::t_p;
	_Damage = 10;
	AttackObj = nullptr;
	_DieAnimationPath = L"";
	_AtkAnimationPath = L"";
	_EftAnimationPath = L"";
	_colorbool = false;
	_atkDelay = 0.5f;

	_MiniSp = new Sprite;
	_MiniSp->Create(L"Units/P/Marine/Idle/i1.png");
	_MiniSp->_scale = { 0.02f,0.02f };
	_MiniSp->isUI = true;
	_MiniSp->_layer = 12;

	_currentState = t_atk;

	isatk = false;
}

Marine::~Marine()
{
}

void Marine::isHit()
{
	cout << "P_MARINE GET HIT!!! " << _Hp <<" "<< _FullHp << endl;
	_currentState = t_atk;
	if (_Hp < 0)
	{
		_visible = false;
	}
}

void Marine::Update()
{
	if (!_visible)
		return;
	switch (_currentState)
	{
	case t_move:
		Movement();
		break;
	case t_atk:
		Attack();
		break;
	}
}

void Marine::Attack()
{

	if (isatk)
	{
		lookAt(AttackObj);
		if (Animation(L"Units/P/Marine/Attack/a", 14, 0.03f, 3))
		{
			AttackObj->_Hp -= _Damage;
			AttackObj->isHit();
			isatk = false;
		}
		return;
	}

	for (auto it : OBJManager::GetInstance()->E_Units)
	{ 
		if (it->_visible)
		{
			if (GetDistance(it) < _range)
			{
				_atkDelay -= Time::deltaTime;
				if (_atkDelay < 0)
				{
					AttackObj = it;
					_atkDelay = 3;
					isatk = true;
					return;
				}
			}
		}
	}
	idle();
}

void Marine::Movement()
{
	Animation(L"Units/P/Marine/walk/w", 3, 0.1f, 2);
	if (GoTo(_movePos, 300))
	{
		_currentState = t_atk;
	}
}

void Marine::idle()
{
	Animation(L"Units/P/Marine/Idle/i", 3, 0.1f, 1);
}

