#pragma once
#include "Sprite.h"
#include "OBJ.h"
class MiniMap :
	public Sprite
{
public:
	MiniMap();
	~MiniMap();
	Sprite* fog;
	void Update() override;
	void SetMiniMap();

	//적 미니는 레이어 포그보다 낮게
	//OBJ메니져를 만들자
};

