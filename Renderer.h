#pragma once
#include "Node.h"
#include "Types.h"
class Renderer : public Singleton<Renderer>
{
public:
	void Render();
	void RemoveRenderTarget(Node * node);
	void AddRenderTarget(Node * node);

private:
	list<Node*> _rendertargets;
	static bool Comp(Node* a, Node* b);
};

