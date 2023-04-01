#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList(/* args */)
{
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList()
{
}

void LinkedList::AddNode(int value)
{
    Node *temp = new Node();
    temp->Item = value;
    temp->Next = nullptr;

    // If list is empty
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
        return;
    }

    // At least 1 node
    tail->Next = temp;
    tail = temp;
}

int LinkedList::DeleteFirst()
{
    if (head == nullptr)
    {
        cout << "List is already empty" << endl;
        return 0;
    }

    int val = head->Item;
    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return val;
    }

    Node *temp = head;
    head = head->Next;
    delete temp;
    temp = nullptr;
    return val;
}

int LinkedList::DeleteLast()
{
    if (head == nullptr)
    {
        cout << "List is already empty" << endl;
        return 0;
    }

    int val = tail->Item;
    if (head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        return val;
    }

    Node *temp = head;
    while (temp->Next != tail)
    {
        temp = temp->Next;
    }

    temp->Next = nullptr;
    delete tail;
    tail = temp;
    return val;
}

void LinkedList::PrintList()
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->Item << endl;
        temp = temp->Next;
    }
}

Node *LinkedList::GetHead()
{
    return head;
    ;
}

Node *LinkedList::GetTail()
{
    return tail;
}

int LinkedList::GetLength()
{
    auto length = 0;
    auto temp = this->GetHead();
    while (temp != nullptr)
    {
        length += 1;
        temp = temp->Next;
    }
    return length;
}

// length recursive takes head as param
//  if(head  == null)
//      return 0;
// return 1 + recucall(head->next);

void LinkedList::InsertAtIth(int value, int position)
{
    if (position < 0)
    {
        cout << "Cannot insert at " << position << endl;
        return;
    }

    auto node = new Node();
    node->Item = value;

    if (position == 0)
    {
        node->Next = head;
        head = node;
        return;
    }

    int count = 0;
    auto temp = head;

    while (count < position - 1 && temp != nullptr)
    {
        temp = temp->Next;
        count++;
    }

    if (temp != nullptr)
    {
        node->Next = temp->Next;
        temp->Next = node;
    }
}

bool LinkedList::SearchList(Node *head, int item)
{
    if (head == nullptr)
        return false;
    if (head != nullptr && head->Item == item)
        return true;

    return SearchList(head->Next, item);
}