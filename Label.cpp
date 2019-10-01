#include "DXUT.h"
#include "Label.h"

void Label::Create_Label(int num)
{
	Delete_Label();
	AddPos = 0;

	for (auto it : to_wstring(num))
	{
		Sprite* s = new Sprite;
		s->_scale = _scale;
		s->isUI = true;
		s->_layer = _layer;
		s->Create(L"font/" + to_wstring(it - 48) + L".png");
		s->_position = { AddPos * s->_scale.x + _position.x,_position.y };
		AddPos += 30;
		sp.push_back(s);
	}
}

void Label::Delete_Label()
{
	for (auto it : sp)
	{
		delete it;
	}
	sp.clear();
}
