#include "DXUT.h"
#include "Map.h"

Map::Map(wstring path)
{
	Create(path);
	_pivot = { 0,0 };
	_position = { 0,0 };
}

Map::~Map()
{
}
