#pragma once
#include "Types.h"
#include "Node.h"
class Camera : public Singleton<Camera>
{
public:
	void CameraInit();
	void Update();

	void SetPos(vector2 v) { camPos.x = v.x, camPos.y = v.y; };

private:
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;

	Node* following;
	vector2 camPos;
};

