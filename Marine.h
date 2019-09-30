#pragma once
#include "OBJ.h"
class Marine :
	public OBJ
{
public:
	Marine();
	~Marine();
	void isHit() override;
	void Update() override;
	void Attack() override;
};

