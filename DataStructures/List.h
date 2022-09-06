#pragma once
#include "Node.h"
using namespace std;

class List {

private:
	PointerNode head;
	PointerNode current;

public:
	List() {
		head = NULL;
		current = NULL;
	}

	List(PointerNode head) {
		this->head = head;
		current = NULL;
	}

	~List();

	void Unshift(int v); // Insert at Beginning
	void Push(int v); // Insert at End
	void Push(string charVal); // Insert at End
	void Splice(int v, int pos); // Insert at Index Position
	bool IsEmpty() { return head == NULL; }
	void Display();
	void DisplayString();
	void Next();
	void First();
	void Last();
	void Pop();
	string PopElement();
	void Shift();
	void RemoveAtIndex(int pos);
	int Length();

	friend class StaticQueue;

};