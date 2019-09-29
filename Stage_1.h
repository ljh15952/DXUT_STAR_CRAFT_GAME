#pragma once
#include "Stage.h"
#include "Map.h"
#include "Camera.h"
class Stage_1 :
	public Stage
{
public:
	Stage_1();
	~Stage_1();
	void Update() override;
	void Collide() override;

	Map* map;
	Sprite* unit1;
	Sprite* unit2;
	Sprite* unit3;

	Sprite* s2;
	Sprite* walls[2];

	Sprite* ex;

	vector2 campos;

	vector<Sprite*> selectUnits;
	vector<Sprite*> activeUnits;
	//Player
};

