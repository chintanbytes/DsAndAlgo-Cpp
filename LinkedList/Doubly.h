class Node
{
private:
public:
    int Item;
    Node *Next;
    Node *Previous;
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList(/* args */);
    ~DoublyLinkedList();

    void AddFirst(int item);
    void AddLast(int item);
    void DeleteFirst();
    void DeleteLast();
};
