#include "Circular.h"

CircularLinkedList::CircularLinkedList(/* args */)
{
    head = nullptr;
}

CircularLinkedList::~CircularLinkedList()
{
}

void CircularLinkedList::Add(int item)
{
    auto temp = new Node();
    temp->Item = item;

    //Empty
    if (head == nullptr)
    {
        head = temp;
        head->Next = head;
    } //Single element
    else if(head->Next == head)
    {
       head->Next = temp;
       temp->Next = head;
    }
    else
    {
        auto current = head;

        //find tail
        while(current->Next != head){
            current = current->Next;
        }

        //replace tail with temp
        current->Next = temp;
        temp->Next = head;
    }
}

void CircularLinkedList::Delete()
{
    //Empty List
    if (head == nullptr)
    {
        return; // empty
    }
    // single node
    else if (head->Next == head)
    {
        delete head;
        head = nullptr;
    }
    else
    {
        auto current = head;

        //find a node before tail
        while(current->Next->Next != head){
            current = current->Next;
        }
        
        //replace tail current
        delete current->Next;
        current->Next = head;       
    }    
}

Node *CircularLinkedList::GetHead()
{
    return this->head;
}
