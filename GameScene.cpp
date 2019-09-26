#include "DXUT.h"
#include "GameScene.h"

void GameScene::Init()
{
	cout << "Init" << endl;
	s = new Sprite;
	s->Create(L"a.jpg");
	s->_position = { 100,100 };

	s2 = new Sprite;
	s2->Create(L"a.jpg");
	s2->_position = { 100,300 };
	Camera::GetInstance()->CameraInit();
}

void GameScene::Update()
{
	Camera::GetInstance()->SetPos(s->_position);
	Camera::GetInstance()->Update();

	if (Director::GetInstance()->onMouseDown())
	{
		cout << "1" << endl;
	}
	else if (Director::GetInstance()->onMouse())
	{
		cout << "2" << endl;
		s->_position.x += 5;
	}
	else if (Director::GetInstance()->onMouseUp())
	{
		cout << "3" << endl;
	//	Director::GetInstance()->ChangeScene(new GameScene);
	}
}

void GameScene::OnExit()
{
	cout << "EXIT" << endl;
}
