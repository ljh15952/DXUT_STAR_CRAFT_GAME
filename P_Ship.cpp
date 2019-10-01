#include "DXUT.h"
#include "P_Ship.h"

P_Ship::P_Ship()
{
	Create(L"Units/P/boat/ABS.png");

	_Hp = 30;
    _FullHp = 30;
	_Speed = 10;
	_range = 100;
	_v = { 1,1 };
	_objtype = T_obj_type::t_ship;
	_teamtype = T_team::t_p;

	AttackObj = nullptr;
    _DieAnimationPath = L"";
	_AtkAnimationPath = L"";
	_EftAnimationPath = L"";
	_colorbool = false;
	_atkDelay = 3;

	_MiniSp = new Sprite;
	_MiniSp->Create(L"Units/P/boat/ABS.png");
	_MiniSp->_scale = { 0.02f,0.02f };
	_MiniSp->isUI = true;
	_MiniSp->_layer = 12;

	_currentState = t_atk;

	//_ShotEft = new Sprite;
	//_ShotEft->Create(_EftAnimationPath +L"1.png");
}

P_Ship::~P_Ship()
{
	 
}

void P_Ship::Update()
{
	
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

void P_Ship::isHit()
{
	cout << "P_SHIP GET HIT!!! " << _Hp <<_FullHp << endl;

}

void P_Ship::Attack()
{
	for (auto it : OBJManager::GetInstance()->E_Units)
	{
		if (GetDistance(it) < _range)
		{
			_atkDelay -= Time::deltaTime;
			if (_atkDelay < 0)
			{
				it->_Hp -= _Damage;
				_atkDelay = 3;
				cout << "ATKATKATKATK" << endl;
				return;
			}
		}
	}
	idle();
}

void P_Ship::Movement()
{
	Animation(L"Units/P/boat/Walk effect/", 4, 0.1f, 2);
	if (GoTo(_movePos, 300))
	{
		_currentState = t_atk;
	}
}

void P_Ship::idle()
{
	Animation(L"Units/P/boat/Idle/", 4, 0.1f,1);
}
