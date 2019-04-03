
#include "GraphSearchApp.h"
#include <stdlib.h>
#include <time.h>



GraphSearchApp::GraphSearchApp(int numOfNodes)
{
	NumberOfNodes = numOfNodes;

	int id = 0;
	Nodes = new Node*[NumberOfNodes];
	for (int i = 0; i < NumberOfNodes; i++) {
		Nodes[i] = new Node(id++);
	}

	AdjMtx = new bool*[NumberOfNodes];
	for (int i = 0; i < NumberOfNodes; i++) {
		AdjMtx[i] = new bool[i];
	}

	Open = std::queue<Node*>();
	Closed = new bool[NumberOfNodes];

	Generate();
}

void GraphSearchApp::Generate() 
{

	//------- Random Generation --------
	//srand(time(NULL));
	//for (int i = 0; i < NumberOfNodes; i++) {
	//	for (int j = 0; j < i; j++) {
	//		SafeAdjSet(i, j, rand() % 2);		
	//	}
	//}

	//------------ Euclidean Generation ------------
	double dim = sqrt(NumberOfNodes);
	for (int y = 0; y < dim; y++) {
		for (int x = 0; x < dim; x++) {
			auto n = (y * dim) + x;
			SafeAdjSet(n, n - 1, true);		//Left
			SafeAdjSet(n, n + 1, true);		//Right
			SafeAdjSet(n, n - dim, true);	//Below
			SafeAdjSet(n, n + dim, true);	//Above
		}
	}
}

bool GraphSearchApp::SafeAdjGet(int n1, int n2) {
	if (n1 == n2 || n1 < 0 || n2 < 0 ||
		n1 >= NumberOfNodes || n2 >= NumberOfNodes)
		return false;
	auto x = (n1 > n2) ? n1 : n2;
	auto y = (n1 < n2) ? n1 : n2;
	return AdjMtx[x][y];
}
void GraphSearchApp::SafeAdjSet(int n1, int n2, bool val) {
	if (n1 == n2 || n1 < 0 || n2 < 0 ||
		n1 >= NumberOfNodes || n2 >= NumberOfNodes)
		throw __uncaught_exception;
	auto x = (n1 > n2) ? n1 : n2;
	auto y = (n1 < n2) ? n1 : n2;
	AdjMtx[x][y] = val;
}

void GraphSearchApp::Search(int start, int target) 
{
	if (start == target || start < 0 || target < 0 ||
		start >= NumberOfNodes || target >= NumberOfNodes)
		throw __uncaught_exception;
	Active = Nodes[start];
	Target = Nodes[start];
	LastNodeAdded = -1;

	Active->Distance = 0;
	Active->Color = 2;
}

void GraphSearchApp::Update(Inputs::Processor *processor, float dt)
{
	if (!Active)
		return;

	while (++LastNodeAdded < NumberOfNodes) {
		if (SafeAdjGet(Active->Id, LastNodeAdded)) {
			auto node = Nodes[LastNodeAdded];
			//Not the active node and not in the closed list.
			if (Active->Id != node->Id && !Closed[node->Id]) {
				node->Color = 1;
				node->Distance = Active->Distance + 1;
				node->Parent = Active;
				Open.push(node);
				if (Target->Id == node->Id)
					Active = nullptr;
				return;
			}
		}
	}
	//Active node gets closed and next node from queue is popped.
	Closed[Active->Id] = true;
	Active = nullptr;
	if (!Open.empty()) {
		Active = Open.front();
		Open.pop();
	}

	
}

void GraphSearchApp::Render(Graphics::Renderer *renderer, float dt)
{

}

GraphSearchApp::~GraphSearchApp()
{
}
