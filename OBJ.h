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
	virtual void Movement() {};
	virtual void idle() {};
	int _Hp;
	int _FullHp;
	int _Damage;
	float _atkDelay;
	float _Speed;
	float _range;
	vector2 _v;
	vector2 _movePos;
	T_obj_type _objtype;
	T_team _teamtype;
	T_state _currentState;
	OBJ* AttackObj;
	wstring _DieAnimationPath;
	wstring _AtkAnimationPath; 
	wstring _EftAnimationPath;


	bool _colorbool;

	Sprite* _MiniSp;
	Sprite* _ShotEft;
};

class OBJManager : public Singleton<OBJManager>
{
public:
	vector<OBJ*> P_Units;
	vector<OBJ*> P_Select_Units;
	vector<OBJ*> E_Units;
};

