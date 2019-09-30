#include "DXUT.h"
#include "P_Ship.h"

P_Ship::P_Ship()
{
	Create(L"Units/P/ABS.png");

	_Hp = 30;
    _FullHp = 30;
	_Speed = 10;
	_v = { 1,1 };
	_objtype = T_obj_type::t_ship;
	AttackObj = nullptr;
    _DieAnimationPath = L"";
	_AtkAnimationPath = L"";
}

P_Ship::~P_Ship()
{
	 
}

void P_Ship::Update()
{
}

void P_Ship::isHit()
{
}

void P_Ship::Attack()
{
}
