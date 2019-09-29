#include "DXUT.h"
#include "Camera.h"

void Camera::CameraInit()
{
	D3DXMatrixOrthoLH(&orthographicMatrix, 1280 , -720 , 0.0f, 1.0f);
	D3DXMatrixIdentity(&identityMatrix);
	_CameraSize = 6;
}

void Camera::Update()
{
	this->viewMatrix = D3DXMATRIX(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-camPos.x, -camPos.y, 0, 1);
	D3DXMatrixOrthoLH(&orthographicMatrix, 1280 * _CameraSize, -720 * _CameraSize, 0.0f, 1.0f);
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
	DXUTGetD3D9Device()->SetTransform(D3DTS_WORLD, &identityMatrix);
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &viewMatrix);
}
