#include <iostream>
#include "Node.h"

class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList(/* args */);
    ~LinkedList();
    void AddNode(int value);
    int DeleteFirst();
    int DeteleLast();
    void PrintList();
};