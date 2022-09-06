#include <iostream>
#include "Node.h"
#include <string>
#pragma once

class Stack {

private:
	PointerNode top;

public:

	Stack() {
		top = NULL;
	}
	int Length();
	bool IsEmpty() { return top == NULL; }
	void Push(std::string value); // Inserts lef to right
	std::string Pop(); // Extract from right LIFO
	void Display(); // Print Stack Values
	std::string GetTop();
};