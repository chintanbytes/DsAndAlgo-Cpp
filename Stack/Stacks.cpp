#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
    T *array;
    int top;
    int size;
    /* data */
public:
    Stack(int size);
    ~Stack();

    int Push(T value);
    T Pop();
    bool IsEmpty();
};

template <typename T>
Stack<T>::Stack(int sz)
{
    size = sz;
    array = new T[sz];
    top = -1;
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] array;
}

template <typename T>
int Stack<T>::Push(T value)
{
    if (top == size - 1)
    {
        int *newArray = new T[size * 2];
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }

        delete[] array;
        array = newArray;
        size = size * 2;
    }

    array[++top] = value;
    return top;
}

template <typename T>
T Stack<T>::Pop()
{
    if (top > -1)
        return array[top--];

    return -1;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
    return top == -1;
}

#include "./../LinkedList/Node.h";
class LinkedListStack
{
private:
    Node *top;
    int size;
    /* data */
public:
    LinkedListStack(/* args */);
    ~LinkedListStack();
    Node *Push(int value);
    void Pop();
    bool IsEmpty();
};

LinkedListStack::LinkedListStack(/* args */)
{
    top = nullptr;
    size = 0;
}

LinkedListStack::~LinkedListStack()
{
}

Node *LinkedListStack::Push(int value)
{
    Node *temp = new Node;
    temp->Item = value;
    temp->Next = top;
    top = temp;

    size++;

    return top;
}

void LinkedListStack::Pop()
{
    // Empty
    if (size == 0)
        return;

    auto temp = top;
    top = top->Next;

    temp->Next = nullptr;
    delete temp;
    size--;
}

bool LinkedListStack::IsEmpty()
{
    return size == 0;
}