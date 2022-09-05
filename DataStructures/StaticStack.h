#pragma once
#include <iostream>
using namespace std;

class StaticStack
{
private:
    int Top;
    int StacticStackArray[5];



public:

    StaticStack() {
        Top = -1;
        for (int i = 0; i < 5; i++) {
            StacticStackArray[i] = 0;
        }
    }

    bool IsEmpty() { return Top < 0; }
    void Push(int v);     //insercion
    void Pop();          //borrado
    void Display();      //temporal 
};