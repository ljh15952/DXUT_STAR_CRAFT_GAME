#include "DXUT.h"
#include "Director.h"
#include"Renderer.h"
LPD3DXSPRITE Director::_sprite;

void Director::Init()
{
	Clicknum = 0;
	_sprite = nullptr;
	_currentScene = nullptr;

	D3DXCreateSprite(DXUTGetD3D9Device(), &_sprite);
}

void Director::Update()
{
	if (_currentScene)
		_currentScene->Update();
	Renderer::GetInstance()->Render();

	GetCursorPos(&p);
	ScreenToClient(DXUTGetHWND(), &p);
}

void Director::ChangeScene(Scene* scene)
{
	if (_currentScene)
	{
		_currentScene->OnExit();
	}
	_currentScene = scene;
	_currentScene->Init();
}

bool Director::onMouseDown()
{
	if (Clicknum == 1)
	{
		Clicknum++;
		return true;
	}
	return false;
}

bool Director::onMouse()
{
	if (Clicknum == 2)
	{
		return true;
	}
	return false;
}

bool Director::onMouseUp()
{
	if (Clicknum == 3)
	{
		Clicknum = 0;
		return true;
	}
	return false;
}
