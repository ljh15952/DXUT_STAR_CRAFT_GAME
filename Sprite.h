#pragma once
#include "Node.h"
#include "Texture.h"
#include "Director.h"
#include "Renderer.h"
class Sprite :
	public Node
{
public:
	Sprite();
	~Sprite();

	void Create(wstring path);
	void AddRenderTarget();

	bool Animation(wstring path, int frame, float delay, int aninum);
	int NowFrame;
	int Aninum;
	float Timer;

	RECT GetRect();

	bool GoTo(vector2 endpos, float Speed);

	Texture2D* texture;

	bool isUI;

	void Draw() override;
};

