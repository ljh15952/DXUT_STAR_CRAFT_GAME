#pragma once
#include "Types.h"
#include "Node.h"
class Camera : public Singleton<Camera>
{
public:
	void CameraInit();
	void Update();

	void SetPos(vector2 v) { camPos.x = v.x, camPos.y = v.y; };

	float _CameraSize;
private:
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;

	vector2 camPos;
};

