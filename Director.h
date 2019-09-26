#pragma once
#include "Scene.h"
#include "Types.h"

class Director : public Singleton<Director>
{
public:
	void Init();
	void Update();

	void ChangeScene(Scene * scene);

	bool onMouseDown();
	bool onMouse();
	bool onMouseUp();

	LPD3DXSPRITE GetSprite() { return _sprite; };

	vector2 GetMousePos() { return vector2((float)p.x,(float)p.y); };
	POINT p;
	int Clicknum;
private:
	static LPD3DXSPRITE _sprite;
	Scene* _currentScene;
};

