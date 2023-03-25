#include "Circular.h"

CircularLinkedList::CircularLinkedList(/* args */)
{
    current = nullptr;
}

CircularLinkedList::~CircularLinkedList()
{
}

void CircularLinkedList::AddBefore(int item)
{
    Node *temp = new Node();
    temp->Item = item;

    if (current == nullptr)
    {
        current = temp;
        current->Next = current;
    }

    temp->Next = current;
    current->Next = temp;
    current = temp;
}
void CircularLinkedList::AddAfter(int item)
{
    Node *temp = new Node();
    temp->Item = item;

    if (current == nullptr)
    {
        current = temp;
        current->Next = current;
    }

    current->Next = temp;
    temp->Next = current;
    current = temp;
}
void CircularLinkedList::Delete()
{
    if (current == nullptr)
        return; // empty

    // single node
    if (current == current->Next)
    {
        delete current;
        current = nullptr;
    }

    Node *temp = current;
    while (temp->Next->Next != current)
    {
        temp = temp->Next;
    }
    temp->Next = current;
}
