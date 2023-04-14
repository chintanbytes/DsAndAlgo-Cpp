#include <gtest/gtest.h>
#include <algorithm>
#include "../Recursion/Recursion.cpp"

using namespace std;

TEST(RecusrionTests, Test_Factorial)
{
    auto rec = new Recursion();
    EXPECT_EQ(24, rec->factorial(4));
    EXPECT_EQ(120, rec->factorial(5));
    EXPECT_EQ(720, rec->factorial(6));
    EXPECT_EQ(-1, rec->factorial(-1));
};

TEST(RecusrionTests, Test_Fibonacci)
{
    auto rec = new Recursion();
    EXPECT_EQ(2, rec->Fibonacci(3));
    EXPECT_EQ(3, rec->Fibonacci(4));
    EXPECT_EQ(5, rec->Fibonacci(5));
    EXPECT_EQ(8, rec->Fibonacci(6));
};