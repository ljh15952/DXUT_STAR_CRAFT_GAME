#pragma once
#include "Sprite.h"
#include "OBJ.h"
class Fog :
	public Sprite
{
public:
	Fog();
	~Fog();

	void SetFog();
	void SetFog(vector<OBJ*> units);
	void Update() override;

	D3DXCOLOR xclr2[25000000];
	D3DLOCKED_RECT LockRect;
	DWORD* pColor;
};

