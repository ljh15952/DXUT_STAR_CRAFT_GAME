#pragma once
#include "Core.h"

class Sprite;
class GameScene :
	public Scene
{
public:
	void Init() override;
	void Update() override;
	void OnExit() override;

	Sprite* s;
	Sprite* s2;

};

