#pragma once
#include "Stage_1.h"
#include "Scene.h"
class GameScene :
	public Scene
{
public:
	void Init() override;
	void Update() override;
	void OnExit() override;
	Stage* stage;
};

