#pragma once
#include "Sprite.h"
#include "OBJ.h"
class MiniMap :
	public Sprite
{
public:
	MiniMap();
	~MiniMap();
	Sprite* fog;
	void Update() override;
	void SetMiniMap();

	//�� �̴ϴ� ���̾� ���׺��� ����
	//OBJ�޴����� ������
};

