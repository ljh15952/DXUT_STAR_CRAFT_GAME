#pragma once
#include "Types.h"
#include "Label.h"
class UIManager : public Singleton<UIManager>
{
public:
	void UIManagerInit();
	vector <Label*> _fullHpLabel;
	vector<Label*> _RemainHpLabel;
	vector<Sprite*> _selectUnitSprite;
};

//�ѵ� �ѵ� �ѵ� �ѵ� ���ǾߵǴµ� ������ �������������鼭 �����ϳ����������̸������ ��������Ʈ�� �����ٲ��ڤ��� ����õ��