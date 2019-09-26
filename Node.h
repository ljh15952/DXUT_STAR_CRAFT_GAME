#pragma once

class Node
{
public:
	Node();
	virtual ~Node() {};

	vector2 _position;
	vector2 _scale;
	vector2 _pivot;
	float _rotation;
	bool _visible;
	COLOR _color;
	int _layer;

	D3DXMATRIX GetMatrix();

	virtual void Draw() {};
	virtual void Update() {};

};

