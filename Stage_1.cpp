#include "DXUT.h"
#include "Stage_1.h"

Stage_1::Stage_1()
{
	map = new Map(L"Stage_1/Map/Stage_1.png");
//	map->_scale = {2,2};

	for (int i = 0; i < 10; i++)
	{
		Sprite* unit1 = new Sprite;
		unit1->Create(L"a.jpg");
		unit1->_position = { 600 + float(100 * i),600 };
		activeUnits.push_back(unit1);
	}
	activeUnits.front()->Create(L"a2.jpg");

	s2 = new Sprite;
	s2->Create(L"a.jpg");
	s2->_position = { 100,100 };

	ex = new Sprite;
	ex->Create(L"z.png");
	ex->_pivot = { 0,0 };
	ex->_scale = { 0.1f,0.1f };
	ex->_position = { -3000,100 };

	for (int i = 0; i < 2; i++)
	{
		walls[i] = new Sprite;
		walls[i]->Create(L"Stage_1/Map/block.png");
		//walls[i]->_visible = false;
	}
	walls[0]->_position = { 1500.34,2101.34 };
	walls[1]->_position = { 3465.07 ,3634.4 };

	campos = { 640,360 };
	Camera::GetInstance()->CameraInit();

	D3DLOCKED_RECT LockRect;

	map->texture->_texture->LockRect(0, &LockRect, 0, D3DLOCK_DISCARD);
	DWORD* pColor = (DWORD*)LockRect.pBits;

	for (int y = 0; y < 5000; ++y)
	{
		for (int x = 0; x < 5000; ++x)
		{
			int nIdx = y * 5000 + x;

			D3DXCOLOR xclr = pColor[nIdx];
			xclr2[nIdx].r = xclr.r;
			xclr2[nIdx].g = xclr.g;
			xclr2[nIdx].b = xclr.b;
			xclr.r = 0.4 - xclr.r;
			xclr.g = 0.4 - xclr.g;
			xclr.b = 0.4 - xclr.b;
			pColor[nIdx] = xclr;
		}
	}
	map->texture->_texture->UnlockRect(0);

}
//0.05
Stage_1::~Stage_1()
{
	delete map;
}

//드래그해서 만들기

void Stage_1::Update()
{
	D3DLOCKED_RECT LockRect;

	map->texture->_texture->LockRect(0, &LockRect, 0, D3DLOCK_DISCARD);
	DWORD* pColor = (DWORD*)LockRect.pBits;


	for (auto it : selectUnits)
	{
		for (int y = it->_position.y - 300; y < it->_position.y + 300; y += 2)
		{
			for (int x = it->_position.x - 300; x < it->_position.x + 300; x += 2)
			{
				int nIdx = y * 5000 + x;

				D3DXCOLOR xclr = pColor[nIdx];
				xclr.r = xclr2[nIdx].r;
				xclr.g = xclr2[nIdx].g;
				xclr.b = xclr2[nIdx].b;
				pColor[nIdx] = xclr;
			}
		}
	}



	map->texture->_texture->UnlockRect(0);











	Camera::GetInstance()->SetPos(campos);
	Camera::GetInstance()->Update();
	if (Director::GetInstance()->onMouseDown())
	{
		for (auto it : selectUnits)
		{
			it->v = vector2(0.1, 0.1); //select 해제
			it->_color = { 1,1,1,1 };
			selectUnits.pop_back();
		}
		ex->_position = (Director::GetInstance()->GetMousePos() * Camera::GetInstance()->_CameraSize);
		ex->_position -= {640 * Camera::GetInstance()->_CameraSize - campos.x, 360 * Camera::GetInstance()->_CameraSize - campos.y};
	}
	else if (Director::GetInstance()->onMouse())
	{
		vector2 m = Director::GetInstance()->GetMousePos() * Camera::GetInstance()->_CameraSize;
		m -= {640 * Camera::GetInstance()->_CameraSize - campos.x, 360 * Camera::GetInstance()->_CameraSize - campos.y};
		vector2 m2 = m - ex->_position;
		ex->_scale = m2 / 30;
	}
	else if (Director::GetInstance()->onMouseUp())
	{
		for (auto it : activeUnits)
		{
			RECT rect2;
			if (IntersectRect(&rect2, &ex->GetRect(), &it->GetRect()))
			{
				it->_color = { 0.8,1,0.8,1 };
				selectUnits.push_back(it);
			}
		}
		ex->_scale = { 0.0001f,0.0001f };

	}





	if (DXUTIsKeyDown('A'))
	{
		s2->_visible = true;
		s2->_position = (Director::GetInstance()->GetMousePos() * Camera::GetInstance()->_CameraSize);
		s2->_position -= {640 * Camera::GetInstance()->_CameraSize - campos.x, 360 * Camera::GetInstance()->_CameraSize - campos.y};

	}
	if (DXUTIsKeyDown('S'))
	{
		s2->_visible = false;
	}
	//s2는 깃발 같은걸로 
	if (s2->_visible)
	{
		for (auto it : selectUnits)
		{
			if (it->GoTo(s2->_position, 300))
				s2->_visible = false;
		}
	}


	if (Director::GetInstance()->GetMousePos().x > 1150)
	{
		campos.x += 50;
	}
	if (Director::GetInstance()->GetMousePos().x < 100)
	{
		campos.x -= 50;
	}
	if (Director::GetInstance()->GetMousePos().y > 650)
	{
		campos.y += 50;
	}
	if (Director::GetInstance()->GetMousePos().y < 100)
	{
		campos.y -= 50;
	}
	RECT rect;
	for (int i = 0; i < 2; i++)
	{
		for (auto it : activeUnits)
		{
			if (IntersectRect(&rect, &walls[i]->GetRect(), &it->GetRect()))
			{
				it->_position -= it->v * 10;
			}
		}
	}

	//맵 10000x10000으로
	//카메라 이동제한
	//미니맵도해야댐;;
	//이정도만하고 클래스화 하자
	//유닛 클릭하면 유닛에 대한 자세한 정보
	//유닛 단체로 선택하면 네모로 뜨기만함 


	for (auto it : selectUnits)
	{
		for (auto it2 : activeUnits)
		{
			if (it != it2)
			{
				while (IntersectRect(&rect, &it->GetRect(), &it2->GetRect()))
				{
					if (it->v.x > 0 && it->v.y < 0)
						it2->v = { 1,-1 };
					else if (it->v.x > 0 && it->v.y > 0)
						it2->v = { 1,1 };
					else if (it->v.x < 0 && it->v.y < 0)
						it2->v = { -1,-1 };
					else if (it->v.x < 0 && it->v.y > 0)
						it2->v = { -1,1 };

					it2->_position += it2->v * 0.01f;
				}
			}
		}
	}


	Collide();
}

void Stage_1::Collide()
{

}
