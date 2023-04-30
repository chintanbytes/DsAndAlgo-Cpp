// Heap is the best way to do it
// Heap is a complete binary tree
// Min nyumber of node in CBT:
// 2^0 + 2^1 + 2^2 + .... + 2^(h-2) + 1 = 2(2^(h-1) - 1)/(2-1) + 1 = 2^(h-1)
// Max number of node in CBT:
//  2^0 + 2^1 + 2^2 + .... + 2^(h-1) = 2(2^h - 1)/(2-1) =  2^h - 1
// min <= number of nodes in a CBT <= max
//  2^(h-1) <= n <= 2^h-1 = O(logn)
// So height in a complete binary tree/heap is logn

// Best way to store CBT is an array where node stored at ith index has a left child at 2i+1 and right child at 2i+2

// Find children indexes(lci and rci) from parent index(i)
// lci = 2i+1, rci = 2i+2

// Find a parent index(i) from child index(ci)
// i = (ci-1)/2

// Two types of heap:
//  1. Max Heap where parent is always greater than child
//  2. Min Heap where parent is always smaller than child

// down heapify in max heap is swapping parent with its largest child
// down heapify in min heap is swapping parent with its smallest child

// up heapify in max heap is swapping child with its smallest  parent
// up heapify in min heap is swapping child with its largest parent

#include <iostream>
#include <vector>
#include <queue>
class PriorityQueue
{
private:
    std::vector<int> pq;
    void downHeapify(int index);
    void upHeapify(int index);

public:
    //declare min priority queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;
    //declare max priority queue
    std::priority_queue<int> maxPQ;
    PriorityQueue(/* args */);
    ~PriorityQueue();
    void insert(int data);
    int removeMin();
    int getMin();
    bool isEmpty();
    int size();
    int at(int index);
    void inplaceHeapSort(int *arr, int n);
};

PriorityQueue::PriorityQueue(/* args */)
{
}

PriorityQueue::~PriorityQueue()
{
}

void PriorityQueue::downHeapify(int index)
{
    // Only element
    if (index == pq.size() - 1)
        return;

    auto lc = 2 * index + 1;
    auto rc = 2 * index + 2;
    auto min = index;

    if (lc < pq.size() && pq.at(lc) < pq.at(min))
    {
        min = lc;
    }
    if (rc < pq.size() && pq.at(rc) < pq.at(min))
    {
        min = rc;
    }
    // already min heap
    if (min == index)
        return;

    auto temp = pq.at(min);
    pq.at(min) = pq.at(index);
    pq.at(index) = temp;

    downHeapify(min);
}

void PriorityQueue::upHeapify(int index)
{
    if (index == 0)
        return;

    auto parent = (index - 1) / 2;

    if (pq.at(index) < pq.at(parent))
    {
        int temp = pq.at(index);
        pq.at(index) = pq.at(parent);
        pq.at(parent) = temp;
        index = parent;
    }
    else
    {
        return;
    }

    upHeapify(index);
}

void PriorityQueue::insert(int data)
{
    pq.push_back(data);
    auto index = pq.size() - 1;
    upHeapify(index);
}

int PriorityQueue::removeMin()
{
    if (isEmpty())
        return 0;

    int min = pq.at(0);

    auto maxIndex = pq.size() - 1;
    pq.at(0) = pq.at(maxIndex);
    pq.at(maxIndex) = min;
    pq.pop_back();

    downHeapify(0);

    return min;
}

int PriorityQueue::getMin()
{
    if (isEmpty())
        return 0;
    return pq.at(0);
}

bool PriorityQueue::isEmpty()
{
    return pq.size() == 0;
}

int PriorityQueue::size()
{
    return pq.size();
}

int PriorityQueue::at(int index)
{
    return pq.at(index);
}

void PriorityQueue::inplaceHeapSort(int *arr, int n)
{
    // create heap first
    for (int x = 1; x < n; x++)
    {
        int i = x;
        while (i > 0)
        {
            auto parent = (i - 1) / 2;

            if (arr[i] < arr[parent])
            {
                int temp = arr[i];
                arr[i] = arr[parent];
                arr[parent] = temp;
                i = parent;
            }
            else
            {
                break;
            }
        }
    }

    // print array here
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Remove min to sort
    auto size =   n;
    while (size >= 1)
    {
        int min = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = min;
        size--;

        int pi = 0;
        while (true)
        {
            auto lc = 2 * pi + 1;
            auto rc = 2 * pi + 2;
            auto currentMin = pi;

            if (lc < size && arr[lc] < arr[currentMin])
            {
                currentMin = lc;
            }
            if (rc < size && arr[rc] < arr[currentMin])
            {
                currentMin = rc;
            }
            // already min heap
            if (currentMin == pi)
                break;

            auto temp = arr[currentMin];
            arr[currentMin] = arr[pi];
            arr[pi] = temp;
            pi = currentMin;
        }
    }

     // print array here
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}