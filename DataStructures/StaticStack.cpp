#include <iostream>
#include"StaticStack.h"
#include <string>

using namespace std;

void StaticStack::Push(string v)
{
    if (Top < (5 - 1))
    {
        Top++;
        StacticStackArray[Top] = v;

    }
    else
        cout << "La pila esta llena";
}

string StaticStack::Pop()
{
    if (!IsEmpty()) {
        Top--;
        return StacticStackArray[Top];
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
