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

//드래그해서 만들기

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
	//s2는 깃발 같은걸로 
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

	//1번과2번이 충돌중일때
	//1번입장에서 2번과 충돌하니 2번의 움직임을뒤로막고
	//2번입장에서 1번과 충돌하니 1번의 움직임을 뒤로막음
	//결론 둘ㄹ다뒤로폭동함
	//카메라 이동제한
	//선택벡터유닛들 색깔 호로로로
	//또뭐하지시바
	//검은색 안개 시스템 이거어케함?ㄹㅇㅋㅋ
	//미니맵도해야댐;;
	//유닛 클릭하면 유닛에 대한 자세한 정보
	//유닛 단체로 선택하면 네모로 뜨기만함 
	//이정도만하고 클래스화 하자

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
