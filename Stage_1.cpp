#include "DXUT.h"
#include "Stage_1.h"

Stage_1::Stage_1()
{
	map = new Map(L"Stage_1/Map/Stage_1.png");
	//	map->_scale = {2,2};

	fog = new Fog;

	for (int i = 0; i < 2; i++)
	{
		ship[i] = new P_Ship;
		ship[i]->_position = { 600 + float(100 * i),600 };
		ship[i]->_scale = { 0.4f,0.4f };
		ship[i]->_layer = 6;
		OBJManager::GetInstance()->P_Units.push_back(ship[i]);
	}

	s2 = new Sprite;
	s2->Create(L"a.jpg");
	s2->_position = { 100,100 };
	s2->_visible = false;
	s2->_layer = 7;

	enemy = new Sprite;
	enemy->Create(L"a.jpg");
	enemy->_position = { 4000,100 };
	enemy->_layer = 4;

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

}
Stage_1::~Stage_1()
{
	delete map;
}

//�巡���ؼ� �����

void Stage_1::Update()
{
	//exampleMini->_position = { minimap->_position.x - (5000 * minimap->_scale.x) + (activeUnits.front()->_position.x * minimap->_scale.x) +240, (activeUnits.front()->_position.y * minimap-> _scale.y) +470  };

	static float t = 0.3f;
	t -= Time::deltaTime;
	if (t < 0)
	{
		fog->SetFog(OBJManager::GetInstance()->P_Units);
		t = 0.3;
	}











	Camera::GetInstance()->SetPos(campos);
	Camera::GetInstance()->Update();
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
	//s2�� ��� �����ɷ� 
	if (s2->_visible)
	{
		for (auto it : OBJManager::GetInstance()->P_Select_Units)
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
		for (auto it : OBJManager::GetInstance()->P_Units)
		{
			if (IntersectRect(&rect, &walls[i]->GetRect(), &it->GetRect()))
			{
				it->_position -= it->v * 10;
			}
		}
	}

	//�� 10000x10000����
	//10000x10000ũ���� �� �̹��� �� fog���ؼ� �������͵� ���̾� ���缭 ���� ���İ��� �ٿ��� �ϱ�
	//ī�޶� �̵�����
	//���������ϰ� Ŭ����ȭ ����
	//���� Ŭ���ϸ� ���ֿ� ���� �ڼ��� ����
	//���� ��ü�� �����ϸ� �׸�� �߱⸸�� 


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


	Collide();
}

void Stage_1::Collide()
{

}
