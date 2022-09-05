#include <iostream>
#include "StaticQueue.h"
using namespace std;

void StaticQueue::Push(int v)
{
    if (back < 5 - 1) {
        ++back;
        StaticQueueArray[back] = v;

    }
    else {
        cout << "La cola esta llena";
    }
}

void StaticQueue::Pop()
{
    if (!IsEmpty()) {
        front++;
    }
    else {
        cout << "La cola esta vacia";
    }
}

void StaticQueue::Display() {
    for (int i = front; i < back + 1; i++) {
        cout << StaticQueueArray[i] << "->" << endl;
    }

    if (IsEmpty()) {
        cout << "La cola esta vacia";
    }
}

