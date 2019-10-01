#include "DXUT.h"
#include "UIManager.h"

void UIManager::UIManagerInit()
{
	for (int i = 0; i < 5; i++)
	{
		Label* l = new Label;
		l->_position = { 280 + float(i*80),600 };
		l->_layer = 200;
		l->_scale = { 0.5,0.5 };
		l->Create_Label(i+5);
		_fullHpLabel.push_back(l);

		Label* l2 = new Label;
		l2->_position = { 320 + float(i * 80),600 };
		l2->_layer = 200;
		l2->_scale = { 0.5,0.5 };
		l2->Create_Label(i+5);
		_RemainHpLabel.push_back(l);
		
		Sprite* s = new Sprite;
		s->_position = { 300 + float(i * 80),550 };
		s->_layer = 200;
		s->_scale = { 0.7,0.7 };
		s->isUI = true;
		s->Create(L"a.jpg");
	    _selectUnitSprite.push_back(s);
	}
	for (int i = 0; i < 5; i++)
	{
		Label* l = new Label;
		l->_position = { 280 + float(i * 80),700 };
		l->_layer = 200;
		l->_scale = { 0.5,0.5 };
		l->Create_Label(i + 15);
		_fullHpLabel.push_back(l);

		Label* l2 = new Label;
		l2->_position = { 320 + float(i * 80),700 };
		l2->_layer = 200;
		l2->_scale = { 0.5,0.5 };
		l2->Create_Label(i + 15);
		_RemainHpLabel.push_back(l);

		Sprite* s = new Sprite;
		s->_position = { 300 + float(i * 80),650 };
		s->_layer = 200;
		s->_scale = { 0.7,0.7 };
		s->isUI = true;
		s->Create(L"a.jpg");
		_selectUnitSprite.push_back(s);
	}
}
