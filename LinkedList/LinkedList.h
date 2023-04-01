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
    int DeleteLast();
    void PrintList();
    Node *GetHead();
    Node *GetTail();
    int GetLength();
    void InsertAtIth(int value, int position);
    bool SearchList(Node *head, int item);
};