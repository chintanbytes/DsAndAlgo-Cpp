#include "Doubly.h"

DoublyLinkedList::DoublyLinkedList(/* args */)
{
    head = nullptr;
    tail = nullptr;
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
        tail = head;
    }
    else
    {
        auto currentHead = head;
        head = temp;
        head->Next = currentHead;
        head->Previous = nullptr;
        currentHead->Previous = head;
    }
}

void DoublyLinkedList::AddLast(int item)
{
    Node *temp = new Node();
    temp->Item = item;

    // Empty List
    if (head == nullptr)
    {
        head = temp;
        head->Next = nullptr;
        head->Previous = nullptr;
        tail = head;
    }
    else
    {
        auto currentTail = tail;
        tail = temp;
        tail->Next = nullptr;
        tail->Previous = currentTail;
        currentTail->Next = tail;
    }
}

void DoublyLinkedList::DeleteFirst()
{
    if (head == nullptr)
    {
        return; // empty
    }
    else if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        auto currentHead = head;
        head = head->Next;
        head->Previous = nullptr;
        delete currentHead;
        currentHead = nullptr;
    }
}

void DoublyLinkedList::DeleteLast()
{
    if (head == nullptr)
    {
        return; // empty list
    }
    else if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        auto currentTail = tail;
        tail = currentTail->Previous;
        tail->Next = nullptr;
        delete currentTail;
        currentTail = nullptr;
    }
}

Node *DoublyLinkedList::GetHead()
{
    return this->head;
}

Node *DoublyLinkedList::GetTail()
{
    return this->tail;
}
