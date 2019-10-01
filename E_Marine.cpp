#include "DXUT.h"
#include "E_Marine.h"

E_Marine::E_Marine()
{
	Create(L"Units/P/ABS.png");
	_layer = 4;
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

	_MiniSp = new Sprite;
	_MiniSp->Create(L"Units/P/ABS.png");
	_MiniSp->_scale = { 0.02f,0.02f };
	_MiniSp->isUI = true;
	_MiniSp->_layer = 4;

}

E_Marine::~E_Marine()
{

}

void E_Marine::Update()
{

}

void E_Marine::isHit()
{

}

void E_Marine::Attack()
{

}
