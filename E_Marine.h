#pragma once
#include "OBJ.h"
class E_Marine :
	public OBJ
{
public:
	E_Marine();
	~E_Marine();
	void Update() override;
	void isHit() override;
	void Attack() override;
};

