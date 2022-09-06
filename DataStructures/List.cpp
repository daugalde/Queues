#include "Node.h"
#include "List.h"

using namespace std;

List::~List()
{
	/*
	PointerNode aux;

	while (head) {
		aux = head;
		head = head->NextNode;
		delete aux;
	}

	head = NULL;
	*/
	
}

int List::Length() {
	int cont = 0;

	PointerNode aux = head;
	if (IsEmpty()) {
		return cont;
	}
	else {
		while (aux != NULL) {
			aux = aux->NextNode;
			cont++;
		}
		return cont;
		cout << endl;
	}

}

void List::Unshift(int v)
{
	if (IsEmpty())
	{
		head = new Node(v);
	}
	else
	{
		head = new Node(v, head);
	}
}

void List::Push(int v)
{
	if (IsEmpty()) {
		head = new Node(v);
	}
	else
	{
		PointerNode aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node(v);
	}
}

void List::Push(std::string charVal)
{
	if (IsEmpty()) {
		head = new Node(charVal);
	}
	else
	{
		PointerNode aux = head;

		while (aux->NextNode != NULL) {
			aux = aux->NextNode;
		}
		aux->NextNode = new Node(charVal);
	}
}

void List::Splice(int v, int pos)
{
	if (IsEmpty()) {
		head = new Node(v);
	}
	else {
		if (pos <= 1)
		{
			Unshift(v);
		}
		else {
			Node* aux = head;
			int i = 2;
			while ((i != pos) && (aux->NextNode != NULL)) {
				i++;
				aux = aux->NextNode;
			}
			PointerNode newNodeFirst = new Node(v);
			newNodeFirst->NextNode = aux->NextNode;
			aux->NextNode = newNodeFirst;
		}
	}
}

void List::Pop()
{
	if (!IsEmpty()) {
		if (head != NULL)
		{ 
			head = head->NextNode;
		}
	}
}

string List::PopElement()
{
	string result = "";
	if (!IsEmpty()) {

		if (head != NULL)
		{
			PointerNode temp = head;
			result = head->charValue;
			head = head->NextNode;
			delete temp;
		}
	}
	return result ;
}

void List::Shift()
{
	if (IsEmpty()) {
		cout << "Empty List:" << endl;
	}
	else {
		if (head->NextNode == NULL)
		{
			PointerNode temp = head;
			head = NULL;
			delete temp;
		}
		else
		{
			PointerNode aux = head;
			head = head->NextNode;
			delete aux;
		}
	}
}

void List::RemoveAtIndex(int index) {
	if (IsEmpty()) {
		cout << "Empty List" << endl;
	}
	else {
		if ((index > Length()) || (index < 0)) {
			cout << "An Index should be greater than zero" << endl;
		}
		else {
			if (index == 1)
			{
				PointerNode temp = head;
				head = head->NextNode;
				delete temp;
			}
			else {
				int cont = 2;
				PointerNode aux = head;
				while (cont < index) {
					aux = aux->NextNode;
					cont++;
				}
				PointerNode temp = aux->NextNode;
				aux->NextNode = aux->NextNode->NextNode;
				delete temp;
			}
		}
	}
}

void List::Display()
{
	Node* aux;
	if (head == NULL) {
		cout << "Empty Here";
	}
	else
	{
		aux = head;
		while (aux)
		{
			cout << aux->value << "-> ";
			aux = aux->NextNode;
		}
		cout << endl;
	}
}

void List::DisplayString()
{
	Node* aux;
	if (head == NULL) {
		cout << "Empty Here";
	}
	else
	{
		aux = head;
		while (aux)
		{
			if (aux->charValue != "" )
			{
				string arrow = "  ->  ";

				PointerNode tmp = aux->NextNode;

				if (tmp == NULL || tmp->charValue == "")
				{
					arrow = "";
				}

				cout << aux->charValue + arrow;
				
			}
			
			aux = aux->NextNode;
		}
		cout << endl;
	}
}

void List::Next()
{
	if (current) current = current->NextNode;
}

void List::First()
{
	current = head;
}

void List::Last()
{
	current = head;
	if (!IsEmpty())
		while (current->NextNode) Next();
}