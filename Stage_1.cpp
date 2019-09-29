#include "DXUT.h"
#include "Stage_1.h"

Stage_1::Stage_1()
{
	map = new Map(L"Stage_1/Map/Stage_1.png");

	unit1 = new Sprite;
	unit1->Create(L"a.jpg");
	unit1->_position = { 100,100 };

	unit2 = new Sprite;
	unit2->Create(L"a.jpg");
	unit2->_position = { 200,100 };

	unit3 = new Sprite;
	unit3->Create(L"a.jpg");
	unit3->_position = { 300,100 };

	activeUnits.push_back(unit1);
	activeUnits.push_back(unit2);
	activeUnits.push_back(unit3);


	s2 = new Sprite;
	s2->Create(L"a.jpg");
	s2->_position = { 100,100 };

	ex = new Sprite;
	ex->Create(L"z.png");
	ex->_pivot = { 0,0 };
	ex->_scale = { 10,10 };
	ex->_position = { 300,100 };

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
	Camera::GetInstance()->SetPos(campos);
	Camera::GetInstance()->Update();

	if (Director::GetInstance()->onMouseDown())
	{
		for (auto it : selectUnits)
		{
			selectUnits.pop_back();
		}
		cout << selectUnits.size() << endl;
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
				selectUnits.push_back(it);
				cout << "ASDASDSD" << endl;
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
		for (auto it : selectUnits)
		{
			it->GoTo(s2->_position, 300);
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
		for (auto it : selectUnits)
		{
			if (IntersectRect(&rect, &walls[i]->GetRect(), &it->GetRect()))
			{
				it->_position -= it->v * 10;
			}
		}
	}

	//1����2���� �浹���϶�
	//1�����忡�� 2���� �浹�ϴ� 2���� ���������ڷθ���
	//2�����忡�� 1���� �浹�ϴ� 1���� �������� �ڷθ���
	//��� �Ѥ��ٵڷ�������
	//ī�޶� �̵�����
	//���ú������ֵ� ���� ȣ�ηη�
	//�ǹ������ù�
	//������ �Ȱ� �ý��� �̰ž�����?��������
	//�̴ϸʵ��ؾߴ�;;
	//���� Ŭ���ϸ� ���ֿ� ���� �ڼ��� ����
	//���� ��ü�� �����ϸ� �׸�� �߱⸸�� 
	//���������ϰ� Ŭ����ȭ ����

	for (auto it : selectUnits)
	{
		for (auto it2 : selectUnits)
		{
			if (it != it2)
			{
				if (IntersectRect(&rect, &it->GetRect(), &it2->GetRect()))
				{
					it2->_position -= it2->v * 20;
				}
			}
		}
	}

	Collide();
}

void Stage_1::Collide()
{

}
