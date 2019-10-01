#pragma once
#include "OBJ.h"
class Marine :
	public OBJ
{
public:
	Marine();
	~Marine();
	void Update() override;
	void isHit() override;
	void Attack() override;
	void Movement() override;
	void idle() override;
};

