class DoublyLinkedListNode
{
private:
public:
    int Item;
    DoublyLinkedListNode *Next;
    DoublyLinkedListNode *Previous;
};

class DoublyLinkedList
{
private:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;

public:
    DoublyLinkedList(/* args */);
    ~DoublyLinkedList();

    void AddFirst(int item);
    void AddLast(int item);
    void DeleteFirst();
    void DeleteLast();

    DoublyLinkedListNode *GetHead();
    DoublyLinkedListNode *GetTail();
};
