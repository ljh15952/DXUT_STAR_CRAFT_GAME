#include "DXUT.h"
#include "Fog.h"

Fog::Fog()
{
	Create(L"Stage_1/Map/fog.png");
	_pivot = { 0,0 };
	_layer = 2;

	SetFog();
}

Fog::~Fog()
{

}

void Fog::SetFog()
{
	texture->_texture->LockRect(0, &LockRect, 0, D3DLOCK_DISCARD);
	pColor = (DWORD*)LockRect.pBits;

	for (int y = 0; y < 5000; ++y)
	{
		for (int x = 0; x < 5000; ++x)
		{
			int nIdx = y * 5000 + x;

			D3DXCOLOR xclr = pColor[nIdx];
			xclr2[nIdx].r = xclr.r;
			xclr2[nIdx].g = xclr.g;
			xclr2[nIdx].b = xclr.b;

			xclr.r = 0.01;
			xclr.g = 0.01;
			xclr.b = 0.01;
			xclr.a = 0.8;
			pColor[nIdx] = xclr;
		}
	}
	texture->_texture->UnlockRect(0);
}

void Fog::SetFog(vector<OBJ*> units)
{
	texture->_texture->LockRect(0, &LockRect, 0, D3DLOCK_DISCARD);
	pColor = (DWORD*)LockRect.pBits;

	for (auto it : units) //active units
	{
		for (int i = it->_position.y - 500; i <= it->_position.y + 500; i += 2)
		{
			for (int j = it->_position.x - 500; j <= it->_position.x + 500; j += 2)
			{
				int d = (int)sqrt((i - it->_position.y) * (i - it->_position.y) + (j - it->_position.x) * (j - it->_position.x));
				if (d <= 500)
				{
					int nIdx = i * 5000 + j;
					if (nIdx >= 25000000 || nIdx <= 0)
					{
						return;
					}
					D3DXCOLOR xclr = pColor[nIdx];
					if (xclr.a > 0)
					{
						xclr.a = 0;
						pColor[nIdx] = xclr;
					}
				}
			}
		}
	}
	texture->_texture->UnlockRect(0);
}

void Fog::Update()
{

}
