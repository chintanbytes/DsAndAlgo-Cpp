#include "Node.h"

class CircularLinkedList
{
private:
    Node *current;

public:
    CircularLinkedList(/* args */);
    ~CircularLinkedList();
    void AddBefore(int item);
    void AddAfter(int item);
    void Delete();
};