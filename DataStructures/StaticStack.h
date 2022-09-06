#pragma once
#include <iostream>
#include <string>
using namespace std;

class StaticStack
{
private:
    int Top;
    string StacticStackArray[5];

public:

    StaticStack() {
        Top = -1;
        for (int i = 0; i < 5; i++) {
            StacticStackArray[i] = "";
        }
    }

    bool IsEmpty() { return Top < 0; }
    void Push(string v);     //insercion
    string Pop();          //borrado
    void Display();      //temporal 
};