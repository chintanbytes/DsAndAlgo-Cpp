#include <gtest/gtest.h>
#include "../Queue/PriorityQueue.cpp"

TEST(PriorityQueueTests, Test_PriorityQueue)
{
    PriorityQueue queue = PriorityQueue();
    queue.insert(100);
    EXPECT_EQ(queue.getMin(), 100);
    EXPECT_EQ(queue.size(), 1);
    queue.insert(10);
    EXPECT_EQ(queue.getMin(), 10);
    EXPECT_EQ(queue.size(), 2);
    queue.insert(15);
    EXPECT_EQ(queue.getMin(), 10);
    EXPECT_EQ(queue.size(), 3);
    queue.insert(4);
    EXPECT_EQ(queue.getMin(), 4);
    EXPECT_EQ(queue.size(), 4);
    queue.insert(17);
    EXPECT_EQ(queue.getMin(), 4);
    EXPECT_EQ(queue.size(), 5);
    queue.insert(21);
    EXPECT_EQ(queue.getMin(), 4);
    EXPECT_EQ(queue.size(), 6);
    queue.insert(67);
    EXPECT_EQ(queue.getMin(), 4);
    EXPECT_EQ(queue.size(), 7);

    for (int i = 0; i < queue.size(); i++)
    {
        std::cout << queue.at(i) << " ";
    }

    std::cout << std::endl;

    EXPECT_EQ(queue.removeMin(), 4);
    EXPECT_EQ(queue.size(), 6);

    EXPECT_EQ(queue.removeMin(), 10);
    EXPECT_EQ(queue.size(), 5);

    EXPECT_EQ(queue.removeMin(), 15);
    EXPECT_EQ(queue.size(), 4);

    EXPECT_EQ(queue.removeMin(), 17);
    EXPECT_EQ(queue.size(), 3);

    EXPECT_EQ(queue.removeMin(), 21);
    EXPECT_EQ(queue.size(), 2);

    EXPECT_EQ(queue.removeMin(), 67);
    EXPECT_EQ(queue.size(), 1);

    EXPECT_EQ(queue.removeMin(), 100);
    EXPECT_EQ(queue.size(), 0);
};

TEST(PriorityQueueTests, Test_InPlaceHeapSort)
{
    PriorityQueue queue = PriorityQueue();
    int arr[] = {100, 10, 15, 4, 17, 21, 67};
    int size = 7;
    queue.inplaceHeapSort(arr, size);
}
