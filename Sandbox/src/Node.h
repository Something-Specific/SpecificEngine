#pragma once
class Node
{
public:

	int Id;
	int Color;
	double Distance;
	Node* Parent;

	Node(int id);
	~Node();
};

