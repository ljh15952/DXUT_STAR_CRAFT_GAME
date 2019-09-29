#pragma once
class Stage
{
public:
	virtual ~Stage() {};
	virtual void Update() {};
	virtual void Collide() {};
};

