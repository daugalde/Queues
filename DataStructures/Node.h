#pragma once
#include <iostream>
#include <string>
class Node {

private:
	std::string charValue = "";
	int value = 0;
	Node* NextNode;


public:  // Constructors

	Node() {
		std::string charValue = "";
		value = 0;
		NextNode = NULL;
	}

	Node(std::string v)
	{
		charValue = v;
		NextNode = NULL;
	}

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

	Node(std::string charVal, Node* newNextNode)
	{
		charValue = charVal;
		NextNode = newNextNode;
	}
	friend class Stack;
	friend class Queue;
	friend class List;
	friend class FileLoader;
};

typedef Node* PointerNode; //Alias
