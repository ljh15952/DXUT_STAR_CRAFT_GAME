#pragma once
#include "Sprite.h"
#include "Types.h"
class OBJ :
	public Sprite
{
public:
	virtual void isHit() {};
	virtual void Update() {};
	virtual void Attack() {};
	int _Hp;
	int _FullHp;
	float _Speed;
	vector2 _v;
	T_obj_type _objtype;
	OBJ* AttackObj;
	wstring _DieAnimationPath;
	wstring _AtkAnimationPath; 
};

class OBJManager : public Singleton<OBJManager>
{
public:
	vector<OBJ*> P_Units;
	vector<OBJ*> P_Select_Units;
	vector<OBJ*> E_Units;
};

