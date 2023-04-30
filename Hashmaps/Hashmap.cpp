#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>

class HashmapNode
{
public:
    std::string key;
    int value;
    HashmapNode *next;
    HashmapNode(std::string key, int value) : key(key), value(value), next(nullptr) {}
    ~HashmapNode()
    {
        delete next;
    }
};

class Hashmap
{
private:
    HashmapNode **bucketArray;
    int bucketSize;
    int base;
    int hash(std::string key);

public:
    Hashmap(int size, int p);
    ~Hashmap();
    void insert(std::string key, int value);
    int getValue(std::string key);
    void erase(std::string key);
    void print();
};

Hashmap::Hashmap(int size, int p)
{
    bucketSize = size;
    base = p;
    bucketArray = new HashmapNode *[bucketSize];
    for (int i = 0; i < bucketSize; i++)
    {
        bucketArray[i] = nullptr;
    }
}

Hashmap::~Hashmap()
{
    for (int i = 0; i < bucketSize; i++)
    {
        delete bucketArray[i];
    }
    delete[] bucketArray;
}

int Hashmap::hash(std::string key)
{
    int sum = 0;
    // Find Hash
    for (int i = key.length() - 1; i >= 0; i--)
    {
        sum += key[i] * pow(base, i);
        sum %= bucketSize;
    }
    // Compress yhe Hash and return
    return sum % bucketSize;
}

void Hashmap::insert(std::string key, int value)
{
    auto calculatedHash = hash(key);

    if (bucketArray[calculatedHash] != nullptr)
    {
        auto head = bucketArray[calculatedHash];
        while (head != nullptr)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }

            head = head->next;
        }

        auto newNode = new HashmapNode(key, value);
        newNode->next = bucketArray[calculatedHash];
        bucketArray[calculatedHash] = newNode;
    }
}

int Hashmap::getValue(std::string key)
{
    auto calculatedHash = hash(key);

    HashmapNode *temp = bucketArray[calculatedHash];
    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    return -1;
}

void Hashmap::erase(std::string key)
{
    auto calculatedHash = hash(key);
    HashmapNode *temp = bucketArray[calculatedHash];
    HashmapNode *prev = nullptr;

    while (temp != nullptr)
    {
        if (temp->key == key)
        {
            if (prev == nullptr)
            {
                bucketArray[calculatedHash] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }

            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void Hashmap::print()
{
    for (int i = 0; i < bucketSize; i++)
    {
        HashmapNode *temp = bucketArray[i];
        while (temp != nullptr)
        {
            std::cout << temp->key << " " << temp->value << std::endl;
        }
    }
}
