#pragma once

#include "Node.h"
#include "Gin.h"
#include <queue>

using namespace Gin;
class GraphSearchApp
{
public:
	
	Node* Active;
	Node* Target;
	int LastNodeAdded;

	Node** Nodes;
	bool** AdjMtx;
	int NumberOfNodes;
	
	std::queue<Node*> Open;
	bool* Closed;

	GraphSearchApp(int);
	~GraphSearchApp();

	void Generate();
	void Search(int, int);
	void Update(Inputs::Processor *processor, float dt);
	void Render(Graphics::Renderer *renderer, float dt);

	bool SafeAdjGet(int, int);
	void SafeAdjSet(int, int, bool);
};

