#pragma once
#include "OBJ.h"
class P_Ship :
	public OBJ
{
public:
	P_Ship();
	~P_Ship();
	void Update() override;
	void isHit() override;
	void Attack() override;
};

