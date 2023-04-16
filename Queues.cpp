#include <iostream>
#include "./LinkedList/Node.h"

using namespace std;
class Queues
{
private:
    Node *head;
    Node *tail;
    int count;

public:
    Queues(/* args */);
    ~Queues();
    int Enqueue(int val);
    int Dequeue();
    void PrintQueue();
    bool IsEmpty();
};

Queues::Queues(/* args */)
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

Queues::~Queues()
{
}

int Queues::Enqueue(int val)
{
    auto *newNode = new Node;
    newNode->Item = val;
    newNode->Next = nullptr;

    if (count <= 0)
    {
        cout << "Queue is empty. Adding first node" << endl;
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->Next = newNode;
        tail = newNode;
    }
    return ++count;
}

int Queues::Dequeue()
{
    if (count <= 0)
    {
        cout << "Queue is empty. Nothing to dequeue" << endl;
        return -1;
    }
    else
    {
        auto temp = head;
        auto retValue = temp->Item;
        head = head->Next;
        temp->Next = nullptr;
        delete temp;
        --count;
        return retValue;
    }
}

void Queues::PrintQueue()
{
    auto current = head;
    while (current != nullptr)
    {
        cout << current->Item << endl;
        current = current->Next;
    }
}

bool Queues::IsEmpty()
{
    return count == 0;
}
