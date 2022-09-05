#include <iostream>
#include "Node.h"
#include "Queue.h"
using namespace std;

void Queue::Push(int num) {

	if (front == NULL) { // First element
		front = new Node(num);
		back = front;
	}
	else { // Rest elements
		back = new Node(num, back);
	}

};

int Queue::Pop() {

	int numero = 0;
	if (front == NULL) { // Empty Queue
		cout << "La cola esta vacia" << endl;
	}
	else if (back == front) { // Single Element
		numero = front->value;
		back = NULL;
		front = NULL;
	}
	else { // 2 or more elements
		numero = front->value;
		PointerNode aux = back;
		while (aux->NextNode != front) {
			aux = aux->NextNode;
		}
		aux->NextNode = NULL;
		front = aux;

	}
	return numero;

};

void Queue::Display() {
	PointerNode aux = back;
	while (aux != NULL) {
		cout << aux->value << " -> ";
		aux = aux->NextNode;
	}
	cout << endl;
};

