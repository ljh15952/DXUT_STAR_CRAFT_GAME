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

//뚜따 뚜따 뚜따 뚜따 가되야되는데 포지션 일정값떨어지면서 어케하나ㅂㄷㅂㄷ미리만들고 스프라이트랑 라벨을바꾸자ㅋ올 ㅋ나천재