#pragma once
#include <iostream>

class Node {

private:
	int value = 0;
	Node* NextNode;


public:  // Constructors

	Node(int v)
	{
		value = v;
		NextNode = NULL;
	}

	Node(int v, Node* newNextNode)
	{
		value = v;
		NextNode = newNextNode;
	}
	friend class Queue;
};

typedef Node* PointerNode; //Alias
