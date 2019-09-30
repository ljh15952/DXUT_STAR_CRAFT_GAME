#pragma once
#include "Stage.h"
#include "Map.h"
#include "Camera.h"
#include "P_Ship.h"
#include "Fog.h"
class Stage_1 :
	public Stage
{
public:
	Stage_1();
	~Stage_1();
	void Update() override;
	void Collide() override;

	Map* map;
	Fog* fog;

	P_Ship* ship[2];

	Sprite* s2;
	Sprite* walls[2];

	Sprite* ex;

	Sprite* enemy;



	vector2 campos;

	D3DXCOLOR xclr2[25000000];
	//Player
};

