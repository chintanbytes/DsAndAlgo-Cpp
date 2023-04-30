#include <gtest/gtest.h>
#include "../Tree/BinaryTree.cpp"

using namespace std;
struct BinaryTreeTests : public testing::Test
{
    BinaryTree<int> *tree;

    virtual void SetUp() override
    {
        std::cout << "Setting up test fixture" << std::endl;
        tree = new BinaryTree<int>();
    }

    virtual void TearDown() override
    {
        std::cout << "Cleaning up after tests" << std::endl;
        delete tree;
    }
};

TEST_F(BinaryTreeTests, Test_Build_Simple)
{
    // tree->Build();
    // tree->Travers();
    // auto count = tree->CountNodes();
    // EXPECT_EQ(1, count);
    // auto MaxDepth = tree->TreeHeight();
    // EXPECT_EQ(1, MaxDepth);

    // auto isSymmetric = tree->IsSymmetric();
    // EXPECT_TRUE(isSymmetric);
}