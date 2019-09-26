#pragma once
#include "Sprite.h"
#include "Node.h"
class Label : public Node
{
public:
	vector<Sprite*> sp;
	void Create_Label(int num);
	void Delete_Label();
	int AddPos;
};

