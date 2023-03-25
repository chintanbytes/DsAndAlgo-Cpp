#include "Doubly.h"

DoublyLinkedList::DoublyLinkedList(/* args */)
{
    head = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

void DoublyLinkedList::AddFirst(int item)
{

    Node *temp = new Node();
    temp->Item = item;
    // Empty
    if (head == nullptr)
    {
        head = temp;
        head->Next = nullptr;
        head->Previous = nullptr;
    }

    temp->Next = head;
    temp->Previous = nullptr;
    head->Previous = temp;
    head = temp;
}

void DoublyLinkedList::AddLast(int item)
{
    if (head == nullptr)
    {
        head = new Node();
        head->Item = item;
        head->Next = nullptr;
        head->Previous = nullptr;
    }

    Node *current = head;
    while (current->Next != nullptr)
    {
        current = current->Next;
    }
    current->Next = new Node();
    current->Next->Item = item;
    current->Next->Next = nullptr;
    current->Next->Previous = current;
}

void DoublyLinkedList::DeleteFirst()
{
    if (head == nullptr)
        return; // empty

    // Single node
    int ret = head->Item;
    if (head->Next == nullptr)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        head = head->Next;
        delete head->Previous;
        head->Previous = nullptr;
    }
}

void DoublyLinkedList::DeleteLast()
{
    if (head == nullptr)
        return; // empty

    // Single node
    if (head->Next == nullptr)
    {
        delete head;
        head = nullptr;
    }

    Node *current = head;
    while (current->Next->Next != nullptr)
    {
        current = current->Next;
    }
    delete current->Next;
    current->Next = nullptr;
}