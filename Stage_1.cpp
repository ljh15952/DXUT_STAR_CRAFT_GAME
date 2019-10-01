#include "DXUT.h"
#include "Stage_1.h"
#include "Marine.h"
#include "E_Marine.h"
//�� 10000x10000����
//ī�޶� �̵�����
//�����ϳ��ϳ� �ٸ����ʿ�� �����Ű�����
//�ο�°͸������
//���� Ŭ���ϸ� ���ֿ� ���� �ڼ��� ����
//���� ��ü�� �����ϸ� �׸�� �߱⸸�� 

Stage_1::Stage_1()
{
	map = new Map(L"Stage_1/Map/Stage_1.png");
	//	map->_scale = {2,2};

	fog = new Fog;

	for (int i = 0; i < 2; i++)
	{
		P_Ship* s = new P_Ship;
		s->_position = { 600 + float(300 * i),600 };
		s->_scale = { 0.4f,0.4f };
		s->_layer = 6;
		OBJManager::GetInstance()->P_Units.push_back(s);
	}

	for (int i = 0; i < 5; i++)
	{
		Marine* s = new Marine;
		s->_position = { 600 + float(150 * i),1400 };
		s->_scale = { 0.2f,0.2f };
		s->_layer = 6;
		OBJManager::GetInstance()->P_Units.push_back(s);
	}

	for (int i = 0; i < 5; i++)
	{
		E_Marine* s = new E_Marine;
		s->_position = { 4000 + float(150 * i),1400 };
		s->_scale = { 0.2f,0.2f };
		s->_layer = 1;
		OBJManager::GetInstance()->E_Units.push_back(s);
	}

	minimap = new MiniMap;

	s2 = new Sprite;
	s2->Create(L"a.jpg");
	s2->_position = { 100,100 };
	s2->_visible = false;
	s2->_layer = 7;

	ex = new Sprite;
	ex->Create(L"z.png");
	ex->_pivot = { 0,0 };
	ex->_scale = { 0.1f,0.1f };
	ex->_position = { -3000,100 };
	ex->_layer = 8;

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

	UIManager::GetInstance()->UIManagerInit();
}
Stage_1::~Stage_1()
{
	delete map;
}

//�巡���ؼ� �����

void Stage_1::Update()
{
	Camera::GetInstance()->SetPos(campos);
	Camera::GetInstance()->Update();

	//�Ȱ� ������Ʈ
	static float t = 0.3f;
	t -= Time::deltaTime;
	if (t < 0)
	{
		fog->SetFog(OBJManager::GetInstance()->P_Units);
		t = 0.3;
	}
	//

	//���콺 ����
	if (Director::GetInstance()->onMouseDown())
	{
		for (auto it : OBJManager::GetInstance()->P_Select_Units)
		{
			it->v = vector2(0.1, 0.1); //select ����
			it->_color = { 1,1,1,1 };
			OBJManager::GetInstance()->P_Select_Units.pop_back();
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
		for (auto it : OBJManager::GetInstance()->P_Units)
		{
			RECT rect2;
			if (IntersectRect(&rect2, &ex->GetRect(), &it->GetRect()))
			{
				it->_color = { 0.8,1,0.8,1 };
				OBJManager::GetInstance()->P_Select_Units.push_back(it);
			}
		}
		ex->_scale = { 0.0001f,0.0001f };

	}
	//

	//���� ��¦��¦�ϴ°�
	for (auto it : OBJManager::GetInstance()->P_Select_Units)
	{
		if (it->_color.r < 0)
			it->_colorbool = !it->_colorbool;
		else if (it->_color.r > 1)
			it->_colorbool = !it->_colorbool; 

		if (it->_colorbool)
		{
			it->_color.r -= 0.05f;
		}
		else if (!it->_colorbool)
		{
			it->_color.r += 0.05f;
		}
	}
	//

	if (DXUTIsKeyDown('A'))
	{
		s2->_visible = true;
		s2->_position = (Director::GetInstance()->GetMousePos() * Camera::GetInstance()->_CameraSize);
		s2->_position -= {640 * Camera::GetInstance()->_CameraSize - campos.x, 360 * Camera::GetInstance()->_CameraSize - campos.y};

		for (auto it : OBJManager::GetInstance()->P_Select_Units)
		{
			it->_movePos = s2->_position;
			it->_currentState = t_move;
		}
	}
	if (DXUTIsKeyDown('S'))
	{
		s2->_visible = false;
		for (auto it : OBJManager::GetInstance()->P_Select_Units)
		{
			it->_currentState = t_atk;
		}
	}
	//s2�� ��� �����ɷ� 
		


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




	Collide();
}

void Stage_1::Collide()
{
	RECT rect;
	for (int i = 0; i < 2; i++)
	{
		for (auto it : OBJManager::GetInstance()->P_Units)
		{
			if (IntersectRect(&rect, &walls[i]->GetRect(), &it->GetRect()))
			{
				it->_position -= it->v * 10;
			}
		}
	}



	for (auto it : OBJManager::GetInstance()->P_Select_Units)
	{
		for (auto it2 : OBJManager::GetInstance()->P_Units)
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
}