#pragma once
#include "Stage.h"
#include "Map.h"
#include "Camera.h"
#include "P_Ship.h"
#include "Fog.h"
#include "MiniMap.h"
#include "UIManager.h"
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
	MiniMap* minimap;


	Sprite* s2;
	Sprite* walls[2];

	Sprite* ex;

	vector2 campos;
};