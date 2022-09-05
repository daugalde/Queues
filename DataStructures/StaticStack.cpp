#include <iostream>
#include"StaticStack.h"

using namespace std;

void StaticStack::Push(int v)
{
    if (Top < (5 - 1))
    {
        Top++;
        StacticStackArray[Top] = v;

    }
    else
        cout << "La pila esta llena";
}

void StaticStack::Pop()
{
    if (!IsEmpty()) {
        Top--;
    }
    else {
        cout << "La pila esta vacia";
    }
}

void StaticStack::Display()
{
    for (int i = Top; i >= 0; i--)
    {
        cout << StacticStackArray[i] << "->";
    }
}
