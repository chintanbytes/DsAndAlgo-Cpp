#include <gtest/gtest.h>
#include <algorithm>
#include "../Searching/Searching.cpp"

using namespace std;

TEST(SearchingTests, TEST_BINARY_SEARCH)
{
    auto searching = new Searching();
    int array[] = {1, 2, 3, 4, 5, 6};
    auto result = searching->BinarySearch(array, 6, 2);

    EXPECT_EQ(true, result);

    result = searching->BinarySearch(array, 6, 10);
    EXPECT_EQ(false, result);
};

TEST(SearchingTests, TEST_BINARY_SEARCH_RECURSIVE)
{
    auto searching = new Searching();
    int array[] = {1, 2, 3, 4, 5, 6};

    auto result = searching->BSearchRecursive(array, 2, 0, 5);
    EXPECT_EQ(true, result);

    result = searching->BSearchRecursive(array, 5, 0, 5);
    EXPECT_EQ(true, result);

    result = searching->BSearchRecursive(array, 10, 0, 5);
    EXPECT_EQ(false, result);
};