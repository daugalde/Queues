#include <iostream>
#include "Node.h"
#include "Stack.h"
#include <string>
using namespace std;

int Stack::Length() {
	int cont = 0;

	PointerNode aux = top;
	if (IsEmpty()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
		return cont;
	}
}

string Stack::GetTop() {

	string result = "";
	if (!IsEmpty()) {

		if (top != NULL)
		{
			PointerNode temp = top;
			result = top->charValue;
		}
	}
	return result;
};

void Stack::Push(std::string value) {

	if (top == NULL) {
		top = new Node(value);
	}
	else {
		top = new Node(value, top);
	}

};

string Stack::Pop() {

	string result = "";
	if (!IsEmpty()) {

		if (top != NULL)
		{
			PointerNode temp = top;
			result = top->charValue;
			top = top->NextNode;
			delete temp;
		}
	}
	return result;
};

void Stack::Display() {
	PointerNode aux = top;
	while (aux != NULL) {
		cout << aux->charValue << " -> ";
		aux = aux->NextNode;
	}
	cout << endl;
};

