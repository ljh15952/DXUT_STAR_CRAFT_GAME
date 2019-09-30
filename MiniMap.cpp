#include "DXUT.h"
#include "MiniMap.h"

MiniMap::MiniMap()
{
	Create(L"Stage_1/Map/Stage_1.png");
	_pivot = { 0,1 };
	_position = { 0,720 };
	isUI = true;
	_layer = 10;
	_scale = { 0.05,0.05 };

	fog = new Sprite;
	fog->Create(L"Stage_1/Map/fog.png");
	fog->_pivot = { 0,1 };
	fog->_position = { 0,720 };
	fog->isUI = true;
	fog->_layer = 11;
	fog->_scale = { 0.05,0.05 };
}

MiniMap::~MiniMap()
{
}

void MiniMap::Update()
{
}

void MiniMap::SetMiniMap()
{
}
