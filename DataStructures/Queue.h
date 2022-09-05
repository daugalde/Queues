#include <iostream>
#include "Node.h"

class Queue {

private:
	PointerNode front;
	PointerNode back;

public:

	Queue() { 
		front = NULL;
		back = NULL;
	}

	void Push(int num); // Inserts lef to right
	int Pop(); // Extract from right FIFO
	void Display(); // Print Queue Values

};
