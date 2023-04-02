#include <gtest/gtest.h>
#include <algorithm>
#include "../Sorting/Sorting.cpp"

using namespace std;

TEST(SortingTests, TEST_SELECTION_SORT)
{
    auto sorting = new Sorting();
    int array[] = {9, 4, 5, 2, 8, 1};
    sorting->SelectionSort(array, 6);

    EXPECT_EQ(1, array[0]);
    EXPECT_EQ(2, array[1]);
    EXPECT_EQ(4, array[2]);
    EXPECT_EQ(5, array[3]);
    EXPECT_EQ(8, array[4]);
    EXPECT_EQ(9, array[5]);
};

TEST(SortingTests, TEST_BUBBLE_SORT)
{
    auto sorting = new Sorting();
    int array[] = {9, 4, 5, 2, 8, 1};
    sorting->BubleSort(array, 6);

    EXPECT_EQ(1, array[0]);
    EXPECT_EQ(2, array[1]);
    EXPECT_EQ(4, array[2]);
    EXPECT_EQ(5, array[3]);
    EXPECT_EQ(8, array[4]);
    EXPECT_EQ(9, array[5]);
};

TEST(SortingTests, TEST_INBUILT_SORT)
{
    int array[] = {9, 4, 5, 2, 8, 1};
    sort(array, array + 6);

    EXPECT_EQ(1, array[0]);
    EXPECT_EQ(2, array[1]);
    EXPECT_EQ(4, array[2]);
    EXPECT_EQ(5, array[3]);
    EXPECT_EQ(8, array[4]);
    EXPECT_EQ(9, array[5]);
};
