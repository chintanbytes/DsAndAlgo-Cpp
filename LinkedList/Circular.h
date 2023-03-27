#include "Node.h"

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList(/* args */);
    ~CircularLinkedList();
    void Add(int item);
    void Delete();
    Node* GetHead();
};