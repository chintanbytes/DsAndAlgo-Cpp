#include <gtest/gtest.h>
#include "..\Queue\Queues.cpp"

TEST(QueueTests, TEST_ENQUEUE)
{
    auto queue = new Queues;

    EXPECT_EQ(true, queue->IsEmpty());
    int count = queue->Enqueue(10);
    EXPECT_EQ(false, queue->IsEmpty());
    EXPECT_EQ(1, count);
};

TEST(QueueTests, TEST_DEQUEUE_FROM_EMPTY)
{
    auto queue = new Queues;
    EXPECT_EQ(true, queue->IsEmpty());
    int val = queue->Dequeue();
    EXPECT_EQ(-1, val);
};

TEST(QueueTests, TEST_FIRST_IN_FIRST_OUT)
{
    auto queue = new Queues;

    EXPECT_EQ(true, queue->IsEmpty());
    int count = queue->Enqueue(10);
    EXPECT_EQ(1, count);
    count = queue->Enqueue(20);
    EXPECT_EQ(2, count);
    EXPECT_EQ(false, queue->IsEmpty());

    // Now test Dequeue
    int val = queue->Dequeue();
    EXPECT_EQ(10, val);
    val = queue->Dequeue();
    EXPECT_EQ(20, val);
    EXPECT_EQ(true, queue->IsEmpty());

    // Now test dequeue from empty
    val = queue->Dequeue();
    EXPECT_EQ(-1, val);
};

TEST(QueueTests, Test_Print)
{
    auto queue = new Queues;

    EXPECT_EQ(true, queue->IsEmpty());

    int count = queue->Enqueue(10);
    EXPECT_EQ(1, count);

    count = queue->Enqueue(20);
    EXPECT_EQ(2, count);

    EXPECT_EQ(false, queue->IsEmpty());

    queue->PrintQueue();
}