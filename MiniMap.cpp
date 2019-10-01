#include "DXUT.h"
#include "MiniMap.h"

MiniMap::MiniMap()
{
	Create(L"Stage_1/Map/Stage_1.png");
	_pivot = { 0,1 };
	_position = { 0,720 };
	isUI = true;
	_layer = 3;
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
	for (auto it : OBJManager::GetInstance()->P_Units)
	{
		it->_MiniSp->_position = { _position.x - (5000 * _scale.x) + (it->_position.x * _scale.x) + 240, (it->_position.y * _scale.y) + 470 };
		it->_MiniSp->_rotation = it->_rotation;
	}

	for (auto it : OBJManager::GetInstance()->E_Units)
	{
		it->_MiniSp->_position = { _position.x - (5000 * _scale.x) + (it->_position.x * _scale.x) + 240, (it->_position.y * _scale.y) + 470 };
		it->_MiniSp->_rotation = it->_rotation;
	}
}

void MiniMap::SetMiniMap()
{
}
