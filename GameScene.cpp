#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	stage = new Stage_1;
}

void GameScene::Update()
{
	stage->Update();
}

void GameScene::OnExit()
{
	cout << "EXIT" << endl;
	delete stage;
}
