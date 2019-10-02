#include "DXUT.h"
#include "Renderer.h"

void Renderer::Render()
{
	for (auto it : _rendertargets)
	{
		it->Draw();
		it->Update();
	}
}

void Renderer::RemoveRenderTarget(Node* node)
{
	_rendertargets.remove(node);
}

void Renderer::AddRenderTarget(Node* node)
{
	if (find(_rendertargets.begin(), _rendertargets.end(), node) != _rendertargets.end())
		return;
	_rendertargets.push_back(node);
	_rendertargets.sort(Comp);
}

bool Renderer::Comp(Node* a, Node* b)
{
	return (a->_layer < b->_layer);
}
