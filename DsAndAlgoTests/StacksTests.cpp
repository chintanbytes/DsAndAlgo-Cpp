#include <gtest/gtest.h>
#include "..\Stacks.cpp"

TEST(StacksTests, TEST_PUSH)
{
    auto stack = new Stack<int>(10);

    EXPECT_EQ(true, stack->IsEmpty());
    int top = stack->Push(10);
    EXPECT_EQ(false, stack->IsEmpty());
    EXPECT_EQ(0, top);
};

TEST(StacksTests, TEST_CANNOT_POP_FROM_EMPTY)
{
    auto stack = new Stack<int>(10);

    EXPECT_EQ(true, stack->IsEmpty());
    int ele = stack->Pop();
    EXPECT_EQ(true, stack->IsEmpty());
    EXPECT_EQ(-1, ele);
};

TEST(StacksTests, TEST_CAN_PUSH_TO_FULL)
{
    auto stack = new Stack<int>(10);
    int top;

    EXPECT_EQ(true, stack->IsEmpty());
    for (int i = 0; i < 10; i++)
    {
        top = stack->Push(i);
    }
    EXPECT_EQ(false, stack->IsEmpty());
    EXPECT_EQ(9, top);

    top = stack->Push(10);
    EXPECT_EQ(10, top);
};

TEST(StacksTests, TEST_PUSH_THEN_POP)
{
    auto stack = new Stack<int>(10);
    int top;

    EXPECT_EQ(true, stack->IsEmpty());
    for (int i = 0; i < 10; i++)
    {
        top = stack->Push(i);
    }
    EXPECT_EQ(false, stack->IsEmpty());
    EXPECT_EQ(9, top);

    top = stack->Push(10);
    EXPECT_EQ(10, top);

    int ele = stack->Pop();
    EXPECT_EQ(10, ele);
};

TEST(StacksTests, TEST_PUSH_SOME_THEN_EMPTY)
{
    Stack<int> stack(10);
    int top;

    EXPECT_EQ(true, stack.IsEmpty());
    for (int i = 0; i < 10; i++)
    {
        top = stack.Push(i);
    }

    EXPECT_EQ(false, stack.IsEmpty());
    EXPECT_EQ(9, top);

    int ele;
    for (int i = 0; i < 10; i++)
    {
        ele = stack.Pop();
    }

    EXPECT_EQ(true, stack.IsEmpty());
    EXPECT_EQ(0, ele);

    ele = stack.Pop();
    EXPECT_EQ(-1, ele);
};