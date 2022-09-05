#pragma once
#include <iostream>
using namespace std;

class StaticQueue
{
private:
    int front;
    int back;
    int StaticQueueArray[5];


public:
    StaticQueue() {
        front = 0;// First In
        back = -1;// Last
        for (int i = 0; i < 5; i++) {
            StaticQueueArray[i] = 0;
        }
    }

    bool IsEmpty() { return back < front; }
    void Push(int v);
    void Pop();
    void Display();
};